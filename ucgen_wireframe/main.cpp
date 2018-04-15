#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

void drawTriangle()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex2f(0.0f,0.5);
    glVertex2f(-0.5f,-0.5f);
    glVertex2f(0.5f,-0.5f);
    glEnd();
    
}

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    
    window.setActive(true);
    
    bool running = true;
    while (running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }
        
        // clear the buffers
        glClearColor(0.3f, 0.3f, 0.3f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glMatrixMode(GL_PROJECTION);
        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        
        glLoadIdentity();
        sf::Vector2u wsize = window.getSize();
        glViewport(0, 0, wsize.x, wsize.y);
        
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glPushMatrix();
        
        drawTriangle();
        
        glPopMatrix();
        
        window.display();
    }
    
    return EXIT_SUCCESS;
}
