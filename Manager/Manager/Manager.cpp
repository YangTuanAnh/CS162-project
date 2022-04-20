// Manager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../include/menu.h"
using namespace std;
int main()
{
    const int screenHeight = 600;
    const int screenWidth = 1200;
    char *ch = nullptr;
    InitWindow(screenWidth, screenHeight, "COURSE MANAGEMENT");
    SetTargetFPS(60);
    short menu = -2;
    Vector2 mousePosition;
    Vector2 touchPosition;
    char a[17] = "\0", b[17] = "\0", bStar[17] = "\0";
    short idCount = 0, passwordCount = 0, role = 0;
    string Class;
    Course cCourse;
    Rectangle rec_Role[] =
        {
            {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 60, 300, 60},
            {GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 + 20, 300, 60}};

    Rectangle rec_Login[] =
        {
            {GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 - 40 - 10, 340, 60},
            {GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 + 40 - 10, 340, 60},
            {GetScreenWidth() / 2 - 130, GetScreenHeight() / 2 + 150 - 10, 140, 60},
            {30, GetScreenHeight() - 70, 140, 60}};

    Rectangle rec_Main[] =
        {
            {GetScreenWidth() / 2 - 120 - 10, GetScreenHeight() / 2 - 100 - 10, 260, 50},
            {GetScreenWidth() / 2 - 120 - 10, GetScreenHeight() / 2 - 50 - 10, 260, 50},
            {GetScreenWidth() / 2 - 120 - 10, GetScreenHeight() / 2 - 0 - 10, 260, 50},
            {GetScreenWidth() / 2 - 120 - 10, GetScreenHeight() / 2 + 50 - 10, 260, 50}};

    Rectangle rec_Profile{30, GetScreenHeight() - 70, 140, 60};

    Rectangle rec_StudentCourse[] =
        {
            {50, GetScreenHeight() / 2 - 130 - 10, GetScreenWidth() - 100, 50},
            {50, GetScreenHeight() / 2 - 80 - 10, GetScreenWidth() - 100, 50},
            {50, GetScreenHeight() / 2 - 30 - 10, GetScreenWidth() - 100, 50},
            {50, GetScreenHeight() / 2 + 20 - 10, GetScreenWidth() - 100, 50},
            {50, GetScreenHeight() / 2 + 70 - 10, GetScreenWidth() - 100, 50},
            {30, GetScreenHeight() - 70, 140, 60}};

    Rectangle rec_detailOfCourseMenu[] =
        {
            {450, 285, 220, 50},
            {30, GetScreenHeight() - 70, 140, 60}};

    Rectangle rec_StudentSchoolYear[] =
        {
            {200, 100, 200, 50},
            {800, 100, 200, 50},
            {200, 200, 200, 50},
            {800, 200, 200, 50},
            {200, 300, 200, 50},
            {800, 300, 200, 50},
            {30, GetScreenHeight() - 70, 140, 60}};

    Rectangle rec_StudentSemester[] =
        {
            {480, GetScreenHeight() / 2 - 80, 240, 50},
            {480, GetScreenHeight() / 2 - 30, 240, 50},
            {480, GetScreenHeight() / 2 + 20, 240, 50},
            {30, GetScreenHeight() - 70, 140, 60}};

    student sStudent;
    user uStaff;
    short indexMouse = -1, indexTouch = -1, CourseOrResult;
    short numSchoolYear = 0;
    while (!WindowShouldClose())
    {
        mousePosition = GetMousePosition();
        touchPosition = GetTouchPosition(0);
        SetMouseCursor(0);
        switch (menu)
        {
        case -2: // Choose Role Menu
            chooseRoleMenu(mousePosition, touchPosition, indexMouse, menu, role, rec_Role);
            break;
        case -1: // Login Menu
            logInMenu(mousePosition, touchPosition, indexMouse, indexTouch, a, b, bStar, menu, true, idCount, passwordCount, uStaff, sStudent, role, rec_Login);
            break;
        case 0: // Main Menu
            mainMenu(mousePosition, touchPosition, indexMouse, menu, b, bStar, passwordCount, sStudent, uStaff, role, rec_Main, CourseOrResult, numSchoolYear);
            break;
        case 1: // View Profile Menu
            viewProfileMenu(mousePosition, touchPosition, indexMouse, sStudent, uStaff, menu, role, rec_Profile, ch);
            break;
        case 2: // Course Student Menu
            courseOrResultStudentMenu(mousePosition, touchPosition, indexMouse, sStudent, menu, cCourse, rec_StudentCourse, ch, CourseOrResult);
            break;
        case 3: // Detail of Course
            detailOfCourseMenu(mousePosition, touchPosition, indexMouse, cCourse, sStudent, menu, rec_detailOfCourseMenu, ch);
            break;
        case 4: // SchoolYear Student Menu
            schoolYearStudentMenu(mousePosition, touchPosition, indexMouse, sStudent, menu, rec_StudentSchoolYear, numSchoolYear);
            break;
        case 5: // Semester Student Menu
            semesterStudentMenu(mousePosition, touchPosition, indexMouse, sStudent, menu, rec_StudentSemester, CourseOrResult);
            break;
        case 6:
            break;
        case 20: // White Menu
            studentWhiteMenu(mousePosition, touchPosition, indexMouse, menu, rec_Profile, CourseOrResult);
            break;
        }
    }
    CloseWindow();
    return 0;
}