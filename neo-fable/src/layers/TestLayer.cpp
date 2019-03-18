#include "TestLayer.hpp"



namespace layers {
	using namespace application;
	using namespace events;

	TestLayer::TestLayer(std::string name, std::shared_ptr<application::Window> win)
		: Layer(name, win)
	{
		float positions[] = {
			  0.0f, 0.0f, // bottom left clockwise  
			  0.0f, 100.0f,
		    100.0f, 100.0f, 
		    100.0f, 0.0f,  
		};

		float colors[] = {
			0.3f, 0.0f, 0.6f,
			0.3f, 1.0f, 0.6f,
			0.0f, 0.0f, 1.0f,
			0.0f, 0.6f, 0.6f,
		};
		
		float texCoords[] = {
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f
		};

		opengl::Buffer posBuffer(positions, 8, 2);
		opengl::Buffer colorBuffer(colors, 12, 3);
		opengl::Buffer texBuffer(texCoords, 8, 2);

		opengl::VertexArray vertices = opengl::VertexArray();

		program = opengl::Program("./data/shaders/tests/texture.vert.shader", "./data/shaders/tests/texture.frag.shader");

		vertices.addBuffer(&posBuffer, 0);
		vertices.addBuffer(&colorBuffer, 1);
		vertices.addBuffer(&texBuffer, 2);

		box = graphics::Renderable(vertices, 4);

		// should be in renderable
		// box.bindTexture("./data/graphics/test.png")
		texture = opengl::Texture("./data/graphics/test.png");
		texture.bind();
		program.setUniform("img", glUniform1i, 0);
	};

	TestLayer::~TestLayer()
	{
	}

	void TestLayer::update()
	{
		window->rCtx.draw(box, program);
	}

	bool TestLayer::onEvent(const events::Event &event)
	{
		ON_EVENT(mouseScroll, { // is this actually better?
			box.rotateZ(e.getY() * 3);
		});

		return false;
	}


	void TestLayer::onMount()
	{

	}
}
