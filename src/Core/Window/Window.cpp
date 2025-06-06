#include "Window.h"

Window::Window() {
  map = new Map();
  map->generate();
  int mapSide = map->blockSide * map->roomSide * map->getGridSize();

  entityManager = new EntityManager();
  camera =
      new Camera(entityManager->player->getPosition(), width, height, mapSide);
  scene = new Scene(entityManager, map, camera, width, height);
  input = new Input(entityManager, scene);
}

void Window::init() {
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, false);

  window = glfwCreateWindow(width, height, "Roguelike", nullptr, nullptr);
  if (window == nullptr) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    exit(1);
  }

  glfwMakeContextCurrent(window);

  glewExperimental = true;
  if (glewInit() != GLEW_OK) {
    std::cout << "Failed to initialize GLEW" << std::endl;
    exit(1);
  }

  glViewport(0, 0, width, height);
  glfwSetKeyCallback(window, Input::callback);

  program = glCreateProgram();
  Shader(program, GL_VERTEX_SHADER).use();
  Shader(program, GL_FRAGMENT_SHADER).use();
  glUseProgram(program);
}

void Window::render() {
  glm::mat4 projection = glm::ortho(0.0f, (float)width, (float)height, 0.0f);
  glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE,
                     glm::value_ptr(projection));

  scene->init();

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    input->handle();
    scene->render();

    glfwSwapBuffers(window);
  }

  glfwTerminate();
}
