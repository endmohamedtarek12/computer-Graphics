
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


float posX = 0.0f, posY = 0.0f;     // «·≈“«Õ… (Translation)
float rotAngle = 0.0f;              // «·œÊ—«‰ (Rotation)
float scaleSize = 1.0f;             //  €ÌÌ— «·ÕÃ„ (Scaling)
bool showHelp = true;               // ·ÊÕ… «·„”«⁄œ…

// œ«·… ·ﬂ «»… «·‰’ ⁄·Ï «·‘«‘… (Visual Feedback)
void drawText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    for (int i = 0; i < strlen(text); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[i]);
    }
}

// —”„ «·Â—„ («·‘ﬂ· «·√Ê·)
void drawPyramid() {
    glBegin(GL_TRIANGLES);
    // Front
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f); 
    glVertex3f(1.0f, -1.0f, 1.0f);
    // Right
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    // Back
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    // Left
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
}

// —”„ «·„ﬂ⁄» («·‘ﬂ· «·À«‰Ì)
void drawCube() {
    // —”„ «·√ÊÃÂ
    glBegin(GL_QUADS);
    // «·ÊÃÂ «··Ì ›Êﬁ
    glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glColor3f(0.0f, 0.5f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.5f); glVertex3f(1.0f, 1.0f, 1.0f);
    // «·ÊÃÂ «··Ì  Õ 
    glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(1.0f, 0.5f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(1.0f, 0.2f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    // «·ÊÃÂ «··Ì ﬁœ«„
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    // «·ÊÃÂ «··Ì Ê—«
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f); 
    glVertex3f(-1.0f, 1.0f, -1.0f); 
    glVertex3f(1.0f, 1.0f, -1.0f);
    // «·ÊÃÂ «··Ì Ì„Ì‰
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    // «·ÊÃÂ «··Ì ‘„«·
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glEnd();
}

void animate(int value) {
    rotAngle += 1.0f;

    if (rotAngle > 360)
        rotAngle -= 360;

    float speed = .01f;
    posX += speed;

    if (posX > 2.0f || posX < -2.0f)
        speed *= -1;

    glutPostRedisplay();
    glutTimerFunc(16, animate, 0);

   
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 5,
              0, 0, 0,
              0, 1, 0);

    //  ÿ»Ìﬁ «· ÕÊÌ·«  »«· — Ì»
    glPushMatrix();
    glTranslatef(posX, posY, 0.0f);       // 1. «·≈“«Õ…
    glRotatef(rotAngle, 0.0f, 0.0f, 1.0f); // 2. «·œÊ—«‰ ÕÊ· Z
    glScalef(.7f*scaleSize, .7f*scaleSize, .7f*scaleSize); // 3. «·ÕÃ„

    // —”„ «·‘ﬂ·Ì‰ »Ã«‰» »⁄÷Â„«
    glPushMatrix();
    glTranslatef(-1.5f, 0.0f, 0.0f);
    drawPyramid();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5f, 0.0f, 0.0f);
    drawCube();
    glPopMatrix();
    glPopMatrix();

    // ⁄—÷ «· €–Ì… «·»’—Ì… (Visual Feedback)
    if (showHelp) {
        glColor3f(1.0f, 1.0f, 1.0f);
        drawText(-2.3f, 2.0f, "--- Help Panel ---");
        drawText(-2.3f, 1.8f, "Arrows: Move Shapes");
        drawText(-2.3f, 1.6f, "R / L: Rotate CW/CCW");
        drawText(-2.3f, 1.4f, "+ / -: Scale Up/Down");
        drawText(-2.3f, 1.2f, "Space: Reset Transformations");
        drawText(-2.3f, 1.0f, "ESC: Exit");

        char status[100];
        sprintf_s(status, "Pos: (%.1f, %.1f) | Rot: %.0f | Scale: %.1f", posX, posY, rotAngle, scaleSize);
        drawText(-2.3f, -2.0f, status);
    }

    glutSwapBuffers();
}

// «· Õﬂ„ »·ÊÕ… «·„›« ÌÕ
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'r': case 'R': rotAngle -= 5.0f; break;      // œÊ—«‰ ··Ì„Ì‰
    case 'l': case 'L': rotAngle += 5.0f; break;      // œÊ—«‰ ··Ì”«—
    case '+': scaleSize += 0.1f; break;               // “Ì«œ… «·ÕÃ„
    case '-': scaleSize -= 0.1f; if (scaleSize < 0.1) scaleSize = 0.1; break; //  ﬁ·Ì· «·ÕÃ„
    case ' ': // ≈⁄«œ… ÷»ÿ (Reset)
        posX = posY = 0.0f; rotAngle = 0.0f; scaleSize = 1.0f; break;
    case 27: exit(0); break;                          // «·Œ—ÊÃ (ESC)
    }
    glutPostRedisplay();
}

// «· Õﬂ„ »«·√”Â„ ··≈“«Õ…
void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:    posY += 0.1f; break;
    case GLUT_KEY_DOWN:  posY -= 0.1f; break;
    case GLUT_KEY_LEFT:  posX -= 0.1f; break;
    case GLUT_KEY_RIGHT: posX += 0.1f; break;
    }
    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("Computer Graphics Project - Shapes & Transforms");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);    
    glutSpecialFunc(specialKeys);
    glutTimerFunc(0, animate, 0);
    glutMainLoop();
    return 0;
}