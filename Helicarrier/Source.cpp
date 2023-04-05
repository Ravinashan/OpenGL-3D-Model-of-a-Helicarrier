#include <GL/glut.h>  
#include <math.h>
#define PI 3.1415927


//Animation
GLfloat animYRot = 0.0;

//variables to move the camera
GLfloat camX = 0.0;
GLfloat camY = 0.0;
GLfloat camZ = 0.0;

//variables to move the scene
GLfloat sceX = 0.0;
GLfloat sceY = 0.0;
GLfloat sceZ = 0.0;

//variables to move the snowman
GLfloat objX = 0.0;
GLfloat objY = 0.0;
GLfloat objZ = 0.0;

void init() {
    // blue
    //glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
    //white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
   
}

//single fan
void fan() {
    glPushMatrix();
    
    glutSolidSphere(6,10,10);

    glPushMatrix();
    glTranslatef(0,0,5);
    glScalef(1,0.3,1);
    glutSolidCone(5,20,5,5);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(0,0,5);
    glScalef(1, 0.3, 1);
    glutSolidCone(5, 20, 5, 5);
    glPopMatrix();
    glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 0, 5);
    glScalef(1, 0.3, 1);
    glutSolidCone(5, 20, 5, 5);
    glPopMatrix();
    glPushMatrix();
    glRotatef(270, 0, 1, 0);
    glTranslatef(0, 0, 5);
    glScalef(1, 0.3, 1);
    glutSolidCone(5, 20, 5, 5);
    glPopMatrix();

    glPopMatrix();

}

void draw_cylinder(GLfloat radius,
    GLfloat height,
    GLubyte R,
    GLubyte G,
    GLubyte B)
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(R,G,B);
    //glColor3ub(R - 40, G - 40, B - 40);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        glVertex3f(x, y, 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();
  
}


// a single propeller
void propeller() {
    glPushMatrix();
    glTranslatef(0,5,0);
    glRotatef(90, 1, 0, 0);
    draw_cylinder(32,10,1,1,1);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    draw_cylinder(28, 10, 1.0, 1.0, 1.0);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glRotatef(animYRot,0,1,0);
    
    fan();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(0.0, 5.0, 0.0);
    glRotatef(-animYRot, 0, 1, 0);
    fan();
    glPopMatrix();


}

void mainbody() {

    glPushMatrix();
    glScalef(20,2,10);
    //glColor3f(0.2,0.2,0.2);
    glutSolidCube(5);
    glPopMatrix();

}

void sea() {

    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(200.0, 0.0, 200.0);
    glVertex3f(200.0f, 0.0f, -200.0f);
    glVertex3f(-200.0f, 0.0f, -200.0f);
    glVertex3f(-200.0f, 0.0f, 200.0f);
    glEnd();
    glPopMatrix();

}


// plane to be on top of the carrier
void plane() {  
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t * 90.0;

    /// Main body
    glColor3d(0.5, 1, 0);
    glPushMatrix();
    glTranslated(0, 0, 0);
    glScaled(3, 0.4, 0.5);
    glutSolidSphere(1, 30, 30);
    glPopMatrix();

    glColor3d(0, 0, 0);
    glPushMatrix();
    glTranslated(1.7, 0.1, 0);
    glScaled(1.5, 0.7, 0.8);
    glRotated(40, 0, 1, 0);
    glutSolidSphere(0.45, 30, 30);
    glPopMatrix();

    ///Samner Pakha

    ///Right
    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(0, 0, 1.2);
    glRotated(-50, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(25, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(-0.3, -0.15, 1.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();

    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(0.2, -0.15, 0.9);
    glRotated(90, 0, 1, 0);

    /// FAN
//        glPushMatrix();
//            glTranslated(0,0,0.5);
//            glRotated(10*a,0,0,1);
//            glScaled(0.1,0.1,0.1);
//            fan();
//        glPopMatrix();

    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();

    ///Left
    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(0, 0, -1.2);
    glRotated(50, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(-25, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();

    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(-0.3, -0.15, -1.5);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();

    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(0.2, -0.15, -0.9);
    glRotated(90, 0, 1, 0);
    glScaled(0.1, 0.1, 0.9);
    glutSolidTorus(0.5, 0.5, 50, 50);
    glPopMatrix();


    ///Pechoner pakha
    glPushMatrix();
    glTranslated(-2.8, 0, 0);
    glScaled(0.8, 0.5, 0.3);

    ///Right
    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(0.4, 0, 1.5);
    glRotated(-30, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(10, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();

    ///left
    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(0.4, 0, -1.5);
    glRotated(30, 0, 1, 0);
    glScaled(0.7, 0.1, 3);
    glRotated(-10, 0, 1, 0);
    glutSolidCube(1);
    glPopMatrix();
    glPopMatrix();

    /// Pesoner Uporer pakha
    glColor3d(0.8, 1, 0);
    glPushMatrix();
    glTranslated(-2.7, 0.5, 0);
    glRotated(45, 0, 0, 1);
    glScaled(0.8, 2, 0.1);
    glRotated(-20, 0, 0, 1);
    glutSolidCube(0.5);
    glPopMatrix();

    //    glColor3d(0.8,1,0);
    //    glPushMatrix();
    //        glTranslated(-2.95,0.85,0);
    //        glRotated(90,0,1,0);
    //        glScaled(0.05,0.05,0.6);
    //        glutSolidTorus(0.5,0.5,50,50);
    //    glPopMatrix();


        ///FANS

    //    glPushMatrix();
    //        glTranslated(0,0,0);
    //        glRotated(10*a,0,0,1);
    //        //glRotated(90,1,0,0);
    //        fan();
    //    glPopMatrix();
}


//buildings on top of the carrier

void building1() {

    glBegin(GL_QUADS);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 5);
    glVertex3f(5, -5, 5);
    glVertex3f(5, -5, 0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0, 0, 5);
    glVertex3f(-5, 0, 5);
    glVertex3f(-10, -5, 5);
    glVertex3f(5, -5, 5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-5, 0, 0);
    glVertex3f(-5, 0, 5);
    glVertex3f(-10, -5, 5);
    glVertex3f(-10, -5, 0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0,0,0);
    glVertex3f(-5,0,0);
    glVertex3f(-10, -5, 0);
    glVertex3f(5,-5,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0,0,0);
    glVertex3f(0,0,5);
    glVertex3f(-5,0,5);
    glVertex3f(-5,0,0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(5,-5,0);
    glVertex3f(5,-5,5);
    glVertex3f(-10,-5,5);
    glVertex3f(-10,-5,0);
    glEnd();

}

void gun() {

    glPushMatrix();
    glColor3f(0,0,0);
    glutSolidSphere(2, 1000, 9);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(4, 0, -1);
    glRotatef(10, 0, 1, 0);
    glScalef(6, 1, 1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(4 , 0, 1);
    glRotatef(-5, 0, 1, 0);
    glScalef(6, 1, 1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(4, -2, 0);
    glRotatef(-20, 0, 0, 1);
    glScalef(6, 0.5, 0.5);
    glutSolidCube(1);
    glPopMatrix();



}




void lanesondeck() {

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 6.0, 0.0);
    glVertex3f(-20.0, 6.0, 2.0);
    glVertex3f(45.0, 6.0, 2.0);
    glVertex3f(45.0, 6.0, 0.0);
    glEnd();

}


void drawGrid() {
    GLfloat step = 1.0f;
    GLint line;

    glBegin(GL_LINES);
    for (line = -20; line <= 20; line += step) {
        glVertex3f(line, -0.4, 20);
        glVertex3f(line, -0.4, -20);

        glVertex3f(20, -0.4, line);
        glVertex3f(-20, -0.4, line);
    }
    glEnd();
}

void drawAxes() {

    glBegin(GL_LINES);

    glLineWidth(1.5);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-200, 0, 0);
    glVertex3f(200, 0, 0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, -200, 0);
    glVertex3f(0, 200, 0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, -200);
    glVertex3f(0, 0, 200);

    glEnd();
}

    // human carrying vehicle

void humancarrier() {
    
    // the body

    glPushMatrix();
    glColor3f(0, 0, 0);
    glScalef(0.25, 0.25, 0.25);
    mainbody();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.11, 0.12, 0.13);
    glTranslatef(0, 2, 0);
    glScalef(0.125, 0.125, 0.125);
    mainbody();
    glPopMatrix();

    // the pointy parts at the front and back

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(12, -0.75, 6.5);
    glRotatef(90, 0, 1, 0);
    glScalef(1.3, 0.395, 1);

    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);
    glVertex3f(5, 0, 5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0, 5, 0);
    glVertex3f(10, 5, 0);
    glVertex3f(5, 5, 5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(5,0,5);
    glVertex3f(10,0,0);
    glVertex3f(10,5,0);
    glVertex3f(5,5,5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(10, 0, 0);
    glVertex3f(10, 5, 0);
    glVertex3f(0,5,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);
    glVertex3f(10, 5, 0);
    glVertex3f(0, 5, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(5,0,5);
    glVertex3f(0,0,0);
    glVertex3f(0, 5, 0);
    glVertex3f(5, 5, 5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-12, -0.75, -6.5);
    glRotatef(270, 0, 1, 0);
    glScalef(1.3, 0.395, 1);


    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);
    glVertex3f(5, 0, 5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0, 5, 0);
    glVertex3f(10, 5, 0);
    glVertex3f(5, 5, 5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(5, 0, 5);
    glVertex3f(10, 0, 0);
    glVertex3f(10, 5, 0);
    glVertex3f(5, 5, 5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);
    glVertex3f(10, 5, 0);
    glVertex3f(0, 5, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0);
    glVertex3f(10, 0, 0);
    glVertex3f(10, 5, 0);
    glVertex3f(0, 5, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(5, 0, 5);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 5, 0);
    glVertex3f(5, 5, 5);
    glEnd();
    glPopMatrix();

    // the propellers

    glPushMatrix();
    glScalef(0.1, 0.1, 0.1);
    glTranslatef(90,5,67);
    propeller();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1, 0.1, 0.1);
    glTranslatef(90, 5, -67);
    propeller();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1, 0.1, 0.1);
    glTranslatef(-90, 5, -67);
    propeller();
    glPopMatrix();

    glPushMatrix();
    glScalef(0.1, 0.1, 0.1);
    glTranslatef(-90, 5, 67);
    propeller();
    glPopMatrix();

}  







/*


// clouds for the sky
void drawCloud(float x, float y, float z, float scale) {
    // Set up the cloud geometry as a sphere
    const int numSlices = 20;
    const int numStacks = 20;
    const float radius = 1.0f;
    float theta, phi;
    glm::vec3 p;

    // Set up the cloud material
    glm::vec4 color(1.0f, 1.0f, 1.0f, 0.5f);
    float shininess = 20.0f;

    // Save the current matrix
    glPushMatrix();

    // Translate to the cloud's position
    glTranslatef(x, y, z);

    // Scale the cloud
    glScalef(scale, scale, scale);

    // Set the material properties for the cloud
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, glm::value_ptr(color));
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, glm::value_ptr(color));
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    // Draw the cloud as a sphere
    glBegin(GL_QUADS);
    for (int i = 0; i < numStacks; i++) {
        phi = glm::pi<float>() * ((float)i / numStacks);
        for (int j = 0; j < numSlices; j++) {
            theta = 2.0f * glm::pi<float>() * ((float)j / numSlices);
            p.x = cos(theta) * sin(phi) * radius;
            p.y = cos(phi) * radius;
            p.z = sin(theta) * sin(phi) * radius;
            glNormal3f(p.x, p.y, p.z);
            glVertex3f(p.x, p.y, p.z);
            p.x = cos(theta) * sin(phi + (glm::pi<float>() / numStacks)) * radius;
            p.y = cos(phi + (glm::pi<float>() / numStacks)) * radius;
            p.z = sin(theta) * sin(phi + (glm::pi<float>() / numStacks)) * radius;
            glNormal3f(p.x, p.y, p.z);
            glVertex3f(p.x, p.y, p.z);
            p.x = cos(theta + (2.0f * glm::pi<float>() / numSlices)) * sin(phi + (glm::pi<float>() / numStacks)) * radius;
            p.y = cos(phi + (glm::pi<float>() / numStacks)) * radius;
            p.z = sin(theta + (2.0f * glm::pi<float>() / numSlices)) * sin(phi + (glm::pi<float>() / numStacks)) * radius;
            glNormal3f(p.x, p.y, p.z);
            glVertex3f(p.x, p.y, p.z);
            p.x = cos(theta + (2.0f * glm::pi<float>() / numSlices)) * sin(phi) * radius;
            p.y = cos(phi) * radius;
            p.z = sin(theta + (2.0f * glm::pi<float>() / numSlices)) * sin(phi) * radius;
            glNormal3f(p.x, p.y, p.z);
            glVertex3f(p.x, p.y, p.z);
        }
    }
    glEnd();

    // Restore the previous matrix
    glPopMatrix();
}



*/

void empship() {

    // first ring

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.0, 20.0, -5.0);
    glScalef(2.5, 2.5, 2.5);
    glutSolidTorus(0.275, 0.85, 8, 50);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0.0, 20.0, -5.5);
    glScalef(2.5, 2.5, 2.5);
    glutSolidTorus(0.175, 0.75, 8, 50);
    glPopMatrix();


    // second ring

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.0, 20.0, 5.0);
    glScalef(2.5, 2.5, 2.5);
    glutSolidTorus(0.275, 0.85, 8, 50);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0.0, 20.0, 5.5);
    glScalef(2.5, 2.5, 2.5);
    glutSolidTorus(0.175, 0.75, 8, 50);
    glPopMatrix();

    // middle ring

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.0, 20.0, 0.0);
    glScalef(2.5, 2.5, 2.5);
    glutSolidTorus(0.275, 0.85, 8, 50);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0.0, 20.0, 0.5);
    glScalef(2.5, 2.5, 2.5);
    glutSolidTorus(0.175, 0.75, 8, 50);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0.0, 20.0, -0.5);
    glScalef(2.5, 2.5, 2.5);
    glutSolidTorus(0.175, 0.75, 8, 50);
    glPopMatrix();


    // beam pillers

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.0, 22.0, 2.0);
    glScalef(0.25, 0.65, 7.5);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.0, 18.0, 2.0);
    glScalef(0.25, 0.65, 7.5);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(2.0, 20.0, 2.0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.25, 0.65, 7.5);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-2.0, 20.0, 2.0);
    glRotatef(90, 0, 0, 1);
    glScalef(0.25, 0.65, 7.5);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.147, 22.65, 9);
    glScalef(0.1, 0.24, 0.3);
    glRotatef(90, 0 , 1 , 0 );
    building1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.065, 18.65, 11);
    glScalef(0.1, 0.24, 0.3);
    glRotatef(270, 0, 1, 0);
    building1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 22, 11.0);
    glScalef(0.03, 0.03, 0.03);
    glRotatef(90, 0, 0, 1);
    propeller();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 18, 11.0);
    glScalef(0.03, 0.03, 0.03);
    glRotatef(90, 0, 0, 1);
    propeller();
    glPopMatrix();

}

void helicopter() {

    //main body of the plane

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(8, 0, -4);
    glVertex3f(12, 0, 0);
    glVertex3f(8, 0, 4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(8, 0, -4);
    glVertex3f(8, 0, 4);
    glVertex3f(-6, 0, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(8, 0, -4);
    glVertex3f(8, 3, 0);
    glVertex3f(12, 0, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(8, 0, 4);
    glVertex3f(8, 3, 0);
    glVertex3f(12, 0, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(8, 0, -4);
    glVertex3f(8, 3, 0);
    glVertex3f(-6, 0, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(8, 0, 4);
    glVertex3f(8, 3, 0);
    glVertex3f(12, 0, 0);
    glEnd();


    // back wing of the plane 

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(-5, 0, 0);
    glVertex3f(-6, 0, -4);
    glVertex3f(-7, 0, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(-5, 0, 0);
    glVertex3f(-6, 0, 4);
    glVertex3f(-7, 0, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(-6, 0, -2);
    glVertex3f(-6, 0, 2);
    glVertex3f(-9, 0, 0);
    glEnd();

    // main end

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(-5, 0, 0);
    glVertex3f(-6, 0, -4);
    glVertex3f(-6, 1.5, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(-7, 0, 0);
    glVertex3f(-6, 0, -4);
    glVertex3f(-6, 1.5, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(-5, 0, 0);
    glVertex3f(-6, 0, 4);
    glVertex3f(-6, 2, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(-7, 0, 0);
    glVertex3f(-6, 0, 4);
    glVertex3f(-6, 2, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(-6, 0, -2);
    glVertex3f(-6, 2, 0);
    glVertex3f(-9, 0, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(-6, 0, 2);
    glVertex3f(-6, 2, 0);
    glVertex3f(-9, 0, 0);
    glEnd();

    // wings of the plane

    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex3f(4, 0, -10);
    glVertex3f(8, 0, 0);
    glVertex3f(4, 0, 10);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0, 1, 0);
    glVertex3f(4, 0.02, -10);
    glVertex3f(7, 0.02, 0);
    glVertex3f(6, 0.02, 0);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(0, 1, 0);
    glVertex3f(4, 0.02, 10);
    glVertex3f(7, 0.02, 0);
    glVertex3f(6, 0.02, 0);
    glEnd();

  
    


}


void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHT0);
    GLfloat position[] = { 0,30,100 };
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    GLfloat white1[] = { 0.05,0.05,0.05,1.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, white1);

    GLfloat paleYellow[] = { 1.0,1.0,0.75,1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, paleYellow);
    GLfloat white[] = { 1.0,1.0,1.0,1.0 };
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);


    glMaterialf(GL_FRONT, GL_SHININESS,120.0f);

    GLfloat emission[] = { 0.0 , 0.3 ,0.3 ,1.0 };
    //glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission);


    glPushMatrix();
    // camera orientation (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
    gluLookAt(98.0 + camX, 20.0 + camY, 10.0 + camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glRotatef(sceY, 0.0, 1.0, 0.0);
    glTranslatef(objX, 1.0, objZ);

    //Draw a grid on the xz plane
    glColor3f(1, 1, 1);
    //drawGrid();
    //draw the three axes
    //drawAxes();


    glPushMatrix();
    glColor3f(0.2, 0.9, 0.9);
    glutSolidSphere(500, 200, 20);
    glPopMatrix();


    // jets

    glPushMatrix();
    glScalef(1, 0.8, 0.8);
    glTranslatef(80, 10, 20 );
    helicopter();
    glPopMatrix();


    glPushMatrix();
    glScalef(1, 0.8, 0.8);
    glTranslatef(80, -10, -20);
    helicopter();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 0.8, 0.8);
    glTranslatef(30, -20, 70);
    helicopter();
    glPopMatrix();


    glPushMatrix();
    glScalef(1, 0.8, 0.8);
    glTranslatef(10, 30, -60);
    helicopter();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 0.8, 0.8);
    glTranslatef(-50, 40, 80);
    helicopter();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 0.8, 0.8);
    glTranslatef(-85, -40, -70);
    helicopter();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 0.8, 0.8);
    glTranslatef(-75, 40, 60);
    helicopter();
    glPopMatrix();




    glPushMatrix();
    glScalef(1.5, 1.5, 1.5);
    glTranslatef(5, 0.0, 20.0);
    glRotatef(90, 0, 1, 0);
    empship();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.5, 1.5, 1.5);
    glTranslatef(-20, 0.0, -20.0);
    glRotatef(90, 0, 1, 0);
    empship();
    glPopMatrix();



    //helicarrier body
    glPushMatrix();
    //glScalef(3, 3, 3);
    glColor3f(0.2, 0.2, 0.2);
    mainbody();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.28,0.2,0.2);
    glTranslatef(-75,5,20);
    glRotatef(30,0,1,0);
    mainbody();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    glScalef(0.7, 0.5, 0.7);
    glRotatef(30, 0, 1, 0);
    glTranslatef(-128,25,-14);
    mainbody();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(50,0,30);
    glScalef(0.4, 0.4, 0.4);
    propeller();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(50, 0, -30);
    glScalef(0.4, 0.4, 0.4);
    propeller();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-130, 0, 15);
    glScalef(0.4, 0.4, 0.4);
    propeller();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-110, 0, 70);
    glScalef(0.4, 0.4, 0.4);
    propeller();
    glPopMatrix();
    glPushMatrix();
    //glRotatef(animYRot, 0.0, 1.0, 0.0);
    glRotatef(objY, 0.0, 1.0, 0.0);
    glPopMatrix();

    // jets on top of the helicarrier

    glPushMatrix();
    glTranslatef(35.0, 6.0, 13.0);
    glRotatef(220,0,1,0);
    glScalef(2.5, 2.5, 2.5);
    plane();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20.0, 6.0, 13.0);
    glRotatef(220, 0, 1, 0);
    glScalef(2.5, 2.5, 2.5);
    plane();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(05.0, 6.0, 13.0);
    glRotatef(220, 0, 1, 0);
    glScalef(2.5, 2.5, 2.5);
    plane();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10.0, 6.0, 13.0);
    glRotatef(220, 0, 1, 0);
    glScalef(2.5, 2.5, 2.5);
    plane();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(39.0, 6.0, -13.0);
    glRotatef(40, 0, 1, 0);
    glScalef(2.5, 2.5, 2.5);
    plane();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(24.0, 6.0, -13.0);
    glRotatef(40, 0, 1, 0);
    glScalef(2.5, 2.5, 2.5);
    plane();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(9.0, 6.0, -13.0);
    glRotatef(40, 0, 1, 0);
    glScalef(2.5, 2.5, 2.5);
    plane();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6.0, 6.0, -13.0);
    glRotatef(40, 0, 1, 0);
    glScalef(2.5, 2.5, 2.5);
    plane();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-21.0, 6.0, -13.0);
    glRotatef(40, 0, 1, 0);
    glScalef(2.5, 2.5, 2.5);
    plane();
    glPopMatrix();

    glPushMatrix();
    lanesondeck();
    glPopMatrix();

    // first tower with tube 1

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-37.0,8.0,18.0);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-37.0, 8.0, 18.0);
    glScalef(0.5, 1.5, 0.5);
    glutSolidCube(8);
    glPopMatrix();

    // second tower with tube 2

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-43.0, 8.0, 5.0);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-43.0, 8.0, 5.0);
    glScalef(0.5, 1.5, 0.5);
    glutSolidCube(8);
    glPopMatrix();

    // third tower with tube 3

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(-49.0, 8.0, -8.0);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-49.0, 8.0, -8.0);
    glScalef(0.5, 1.5, 0.5);
    glutSolidCube(8);
    glPopMatrix();

    //buildings

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-55, 20.0, 30);
    glRotatef(30, 0, 1, 0);
    glScalef(1.5,1.5,1.5);
    building1();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-85, 20.0, 18.5);
    glRotatef(30, 0, 1, 0);
    glScalef(1.5, 1.5, 1.5);
    building1();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-100, 20.0, 49);
    glRotatef(30, 0, 1, 0);
    glScalef(1.5, 1.5, 1.5);
    building1();
    glPopMatrix();

    //cylinders

    glPushMatrix();
    glTranslatef(-75, 15, 0);
    glRotatef(90, 1, 0, 0);
    draw_cylinder(3, 5,1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-85, 15, 8);
    glRotatef(90, 1, 0, 0);
    draw_cylinder(3, 5, 1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-95, 15, 16);
    glRotatef(90, 1, 0, 0);
    draw_cylinder(3, 5, 1, 1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-96, 9.2, 38);
    glRotatef(30, 0, 1, 0);
    lanesondeck();
    glPopMatrix();

    // guns
    glPushMatrix();
    glTranslatef(52, 0, 8);
    gun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(52, 0, -8);
    gun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(02, 0, 26);
    glRotatef(-40, 0, 1, 0);
    gun();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(02, 0, -26);
    glRotatef(40, 0, 1, 0);
    gun();
    glPopMatrix();


    // human carriers along with the main Helicarrier
    glPushMatrix();
    glTranslatef(-40, 3, 90);
    humancarrier();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(60, 3, -70);
    humancarrier();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50, 18, -80);
    humancarrier();
    glPopMatrix();








    glPopMatrix();
    glutSwapBuffers();

}

//Animation timer function
void timer(int x) {
    if (animYRot == 360.0)
        animYRot = 0.0;
    else
        animYRot += 2.0;
    glutPostRedisplay();

    glutTimerFunc(5.0, timer, 1);
}

void keyboardSpecial(int key, int x, int y) {
    if (key == GLUT_KEY_UP)
        camY += 1;

    if (key == GLUT_KEY_DOWN)
        camY -= 1;

    if (key == GLUT_KEY_RIGHT)
        sceY += 1;

    if (key == GLUT_KEY_LEFT)
        sceY -= 1;

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'w')
        objX += 1;

    if (key == 's')
        objX -= 1;

    if (key == 'd')
    {
        objZ += 1;
    }
    if (key == 'a')
    {
        objZ -= 1;
    }

    glutPostRedisplay();
}






void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Define the Perspective projection frustum 
    // (FOV_in_vertical, aspect_ratio, z-distance to the near plane from the camera position, z-distance to far plane from the camera position)
    gluPerspective(120.0, aspect_ratio, 1.0, 1000.0);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize( 1920 , 1080 );
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Setup Test");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    

    // keyboard function activation
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecial);
    
    glutTimerFunc(5.0, timer, 1);
    init();
    glutMainLoop();

    return 0;
    
}