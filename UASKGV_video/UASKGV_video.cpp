#include <glut.h>

float fx = 25, fy = 30, fz = 22; //koordinat posisi memandang
float tx = 0, ty = 10, tz = 0; //koordinat tujuan memandang
float sudut = 0; //untuk GLRotate

void LV()
{
    gluLookAt(fx, fy, fz, //melihat ke arah mana
        tx, ty, tz, //arah pandangan
        0, 1, 0); //vector


    GLfloat lightposition[] = { 0, 50, 100, 0.0 };//posisi cahaya
    glLightfv(GL_LIGHT0, GL_POSITION, lightposition);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glEnable(GL_LIGHTING); //mengaktifkan pencahayaan
    glEnable(GL_LIGHT0); //mengaktifkan pencahayaan
    glEnable(GL_DEPTH_TEST); //mengaktifkan efek 3D
    glEnable(GL_COLOR_MATERIAL); //mengaktifkan pewarnaan benda
}

void Gambar() {
    //Bagian bawah
    glBegin(GL_POLYGON); //untuk menggambar bidang datar seperti persegi, segitiga, dll
    glColor3ub(255, 136, 95); //untuk pewarnaan bidang, saya menggunakan warna cokelat untuk ini.
    glVertex3f(-10, 1, -10); glVertex3f(10, 1, -10); //koordinat titik-titik bidang
    glVertex3f(10, 1, 10); glVertex3f(-10, 1, 10);
    glEnd();
    glBegin(GL_POLYGON); 
    glColor3ub(250, 99, 71); 
    glVertex3f(-10, -1, -10); glVertex3f(10, -1, -10);
    glVertex3f(10, -1, 10); glVertex3f(-10, -1, 10);
    glEnd();
    glBegin(GL_POLYGON); 
    glColor3ub(250, 99, 71); 
    glVertex3f(-10, 1, -10); glVertex3f(10, 1, -10);
    glVertex3f(10, -1, -10); glVertex3f(-10, -1, -10);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(250, 99, 71);
    glVertex3f(-10, 1, 10); glVertex3f(10, 1, 10);
    glVertex3f(10, -1, 10); glVertex3f(-10, -1, 10);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 127, 80);
    glVertex3f(-10, 1, 10); glVertex3f(-10, 1, -10);
    glVertex3f(-10, -1, -10); glVertex3f(-10, -1, 10);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 127, 80);
    glVertex3f(10, 1, 10); glVertex3f(10, 1, -10);
    glVertex3f(10, -1, -10); glVertex3f(10, -1, 10);
    glEnd();
    
    //Tiang
    glBegin(GL_POLYGON);
    glColor3ub(250, 99, 71);
    glVertex3f(1, 1, -1); glVertex3f(-1, 1, -1);
    glVertex3f(-1, 25, -1); glVertex3f(1, 25, -1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 145, 95);
    glVertex3f(1, 1, 1); glVertex3f(-1, 1, 1);
    glVertex3f(-1, 25, 1); glVertex3f(1, 25, 1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 127, 80);
    glVertex3f(-1, 1, 1); glVertex3f(-1, 1, -1);
    glVertex3f(-1, 25, -1); glVertex3f(-1, 25, 1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 127, 80);
    glVertex3f(1, 1, 1); glVertex3f(1, 1, -1);
    glVertex3f(1, 25, -1); glVertex3f(1, 25, 1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 127, 80);
    glVertex3f(1, 25, -1); glVertex3f(-1, 25, -1);
    glVertex3f(-1, 25, 1); glVertex3f(1, 25, 1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex3f(0.5, 24.5, -1); glVertex3f(-0.5, 24.5, -1);
    glVertex3f(-0.5, 24.5, 4); glVertex3f(0.5, 24.5, 4);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex3f(0.5, 23.5, -1); glVertex3f(-0.5, 23.5, -1);
    glVertex3f(-0.5, 23.5, 4); glVertex3f(0.5, 23.5, 4);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex3f(0.5, 24.5, -1); glVertex3f(0.5, 24.5, 4);
    glVertex3f(0.5, 23.5, 4); glVertex3f(0.5, 23.5, -1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex3f(-0.5, 24.5, -1); glVertex3f(-0.5, 24.5, 4);
    glVertex3f(-0.5, 23.5, 4); glVertex3f(-0.5, 23.5, -1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex3f(0.5, 24.5, 4); glVertex3f(-0.5, 24.5, 4);
    glVertex3f(-0.5, 23.5, 4); glVertex3f(0.5, 23.5, 4);
    glEnd();

    //Kipas
    glPushMatrix();
    glTranslatef(0.0, 24.0, 0.0);
    glRotatef(sudut, 0, 0, 1);
    glTranslatef(0.0, -24.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex3f(0, 24, 4.1); glVertex3f(0, 18, 4.1);
    glVertex3f(4, 18, 4.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex3f(0, 24, 4.1); glVertex3f(0, 30, 4.1);
    glVertex3f(-4, 30, 4.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex3f(0, 24, 4.1); glVertex3f(-6, 24, 4.1);
    glVertex3f(-6, 20, 4.1);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex3f(0, 24, 4.1); glVertex3f(6, 24, 4.1);
    glVertex3f(6, 28, 4.1);
    glEnd();
    glPopMatrix();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, (GLsizei)w / (GLsizei)h, 1, 300);
    glMatrixMode(GL_MODELVIEW);
}

void tampil()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    LV(); // menjalankan fungsi pencahayaan
    Gambar(); //menjalankan fungsi gambar (menampilkan gambar)
    glutSwapBuffers();
}

void timer(int value)
{
    sudut += 2; //perputaran sudut untuk glRotatef
    glutPostRedisplay();
    glutTimerFunc(20, timer, 0); //variabel sudut dan waktu render akan bertambah/berjalan setiap 20 milisecond
}

void keyboard1(unsigned char key, int x, int y)//mengubah posisi pandang
{
    switch (key) 
    {
    case 'w': fy += 2; break;
    case 's': fy -= 2; break;
    case 'a': fx -= 2; break;
    case 'd': fx += 2; break;
    case 'o': fz -= 2; break;
    case 'l': fz += 2; break;
    }
}

void keyboard2(int key, int x, int y) //mengubah arah pandang
{
    switch (key)
    {
    case GLUT_KEY_PAGE_UP: tz -= 2; break;
    case GLUT_KEY_PAGE_DOWN: tz += 2; break;
    case GLUT_KEY_RIGHT: tx += 2; break;
    case GLUT_KEY_LEFT: tx -= 2; break;
    case GLUT_KEY_UP: ty += 2; break;
    case GLUT_KEY_DOWN: ty -= 2; break;
    }
}

int main(int argc, char** argv) //bagian utama program
{
    glutInit(&argc, argv); //menginisialisasi program
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //mengatur tampilan program
    glutInitWindowPosition(50, 10); //posisi window
    glutInitWindowSize(500, 500); //ukuran window
    glutCreateWindow("Kincir Angin | Windmill"); //nama window
    glClearColor(1, 1, 1, 1); //mengatur warna
    glOrtho(-100, 100, -100, 100, -100, 100); //mengatur batas koordinat di dalam program
    glutDisplayFunc(tampil); //menampilkan titik-titik yang sudah dibuat di fungsi tampil
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard1); //mengaktifkan fungsi keyboard untuk mengatur pandangan
    glutSpecialFunc(keyboard2);
    glutTimerFunc(1, timer, 0); //menjalankan timer
    glutMainLoop();
}
