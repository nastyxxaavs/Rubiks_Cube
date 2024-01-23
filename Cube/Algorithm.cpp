#include "Algorithm.h"
#include "Cube.h"


void Algo::Solve(Cube& Cube) {
    makeWhiteCross(Cube);
    firstLayerSolver(Cube);
    solveMiddleLayer(Cube);
    solveYellowCross(Cube);
    solveYellowFace(Cube);
    solveCornerCubies(Cube);
    solveEdges(Cube);
}

bool Algo::isCross(COLOR color, int index, Cube &cube) {
    face_cube current_face = cube.getFace(index);
    int center = current_face[1][1];
    if (current_face[0][1] == center && current_face[1][2] == center)
        if (current_face[2][1] == center && current_face[1][0] == center) {
            return true;
        }
    return false;
}

bool Algo::isRightWhiteCross(Cube &cube) {
    COLOR_cube current_cube = cube.getCube();
    if (current_cube[5][2][1] == COLOR::ORANGE && current_cube[2][2][1] == COLOR::GREEN)
        if (current_cube[3][2][1] == COLOR::RED && current_cube[4][2][1] == COLOR::BLUE) {
            return true;
        }
    return false;
}


bool Algo::matchCenter(int a, int center) {
    if (a == center) {
        return true;
    }
    return false;
}

void Algo::makeWhiteCross(Cube &cube) {
    int counter = 0;
    COLOR_cube current_cube = cube.getCube();
    while (!isCross(WHITE, 1, cube)) {
        if (current_cube[0][1][0] == COLOR::WHITE) {
            int ce = current_cube[3][0][1]; //current edge
            std::queue<int> Q;
            Q.push(3);
            Q.push(4);
            Q.push(5);
            Q.push(2);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdge(fc, cube, ce);
        }

        if (current_cube[0][0][1] == COLOR::WHITE) {
            int ce = current_cube[4][0][1];
            std::queue<int> Q;
            Q.push(4);
            Q.push(5);
            Q.push(2);
            Q.push(3);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdge(fc, cube, ce);
        }

        if (current_cube[0][1][2] == COLOR::WHITE) {
            int ce = current_cube[5][0][1]; //current edge
            std::queue<int> Q;
            Q.push(5);
            Q.push(2);
            Q.push(3);
            Q.push(4);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdge(fc, cube, ce);
        }

        if (current_cube[0][2][1] == COLOR::WHITE) {
            int ce = current_cube[2][0][1]; //current edge
            std::queue<int> Q;
            Q.push(2);
            Q.push(3);
            Q.push(4);
            Q.push(5);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdge(fc, cube, ce);
        }

        if (current_cube[2][0][1] == COLOR::WHITE) {
            int ce = current_cube[0][2][1]; //current edge
            std::queue<int> Q;
            Q.push(2);
            Q.push(3);
            Q.push(4);
            Q.push(5);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdgeFront(fc, cube, ce);
        }

        if (current_cube[3][0][1] == COLOR::WHITE) {
            int ce = current_cube[0][1][0]; //current edge
            std::queue<int> Q;
            Q.push(3);
            Q.push(4);
            Q.push(5);
            Q.push(2);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdgeFront(fc, cube, ce);
            counter++;
        }

        if (current_cube[4][0][1] == COLOR::WHITE) {
            int ce = current_cube[0][0][1]; //current edge
            std::queue<int> Q;
            Q.push(4);
            Q.push(5);
            Q.push(2);
            Q.push(3);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdgeFront(fc, cube, ce);
        }
        if (current_cube[5][0][1] == COLOR::WHITE) {
            int ce = current_cube[0][1][2]; //current edge
            std::queue<int> Q;
            Q.push(5);
            Q.push(2);
            Q.push(3);
            Q.push(4);
            int i = Q.front();
            Q.pop();
            int fc = current_cube[i][1][1]; //face color
            while (!matchCenter(ce, fc)) {
                cube.Rotate(U);
                i = Q.front();
                Q.pop();
                fc = current_cube[i][1][1];
            }
            SetEdgeFront(fc, cube, ce);
        }
        else {
            if (current_cube[5][1][0] == COLOR::WHITE) {
                cube.Rotate(Fprime);
            }

            else if (current_cube[5][1][2] == COLOR::WHITE) {
                cube.Rotate(Bprime);
            }

            else if (current_cube[3][1][2] == COLOR::WHITE) {
                cube.Rotate(F);
            }

            else if (current_cube[3][1][0] == COLOR::WHITE) {
                cube.Rotate(B);
            }

            else if (current_cube[2][1][2] == COLOR::WHITE) {
                cube.Rotate(R);
            }

            else if (current_cube[2][1][0] == COLOR::WHITE) {
                cube.Rotate(Lprime);
            }

            else if (current_cube[4][1][2] == COLOR::WHITE) {
                cube.Rotate(L);
            }

            else if (current_cube[4][1][0] == COLOR::WHITE) {
                cube.Rotate(Rprime);
            }

            else if (current_cube[2][2][1] == COLOR::WHITE) {
                cube.Rotate(F2);
            }

            else if (current_cube[3][2][1] == COLOR::WHITE) {
                cube.Rotate(L2);
            }

            else if (current_cube[4][2][1] == COLOR::WHITE) {
                cube.Rotate(B2);
            }

            else if (current_cube[5][2][1] == COLOR::WHITE) {
                cube.Rotate(R2);
            }
            counter++;
            if (counter >= 15) {
                cube.Shuffle();
                counter = 0;
            }
            //cube.printRotations();
        }
        //cube.printCube();
    }
}

bool::Algo::isSolvedFirstLayer(Cube& Cube){
    COLOR_cube current_cube = Cube.getCube();
    if(current_cube[1][0][0] == COLOR::WHITE && current_cube[1][0][1] == COLOR::WHITE && current_cube[1][0][2] == COLOR::WHITE && current_cube[1][1][0] == COLOR::WHITE && current_cube[1][1][1] == COLOR::WHITE && current_cube[1][1][2] == COLOR::WHITE && current_cube[1][2][0] == COLOR::WHITE && current_cube[1][2][1] == COLOR::WHITE && current_cube[1][2][2] == COLOR::WHITE){
        if(current_cube[2][1][1] == COLOR::GREEN && current_cube[2][2][0] == COLOR::GREEN && current_cube[2][2][1] == COLOR::GREEN && current_cube[2][2][2] == COLOR::GREEN){
            if(current_cube[4][1][1] == COLOR::BLUE && current_cube[4][2][0] == COLOR::BLUE && current_cube[4][2][1] == COLOR::BLUE && current_cube[4][2][2] == COLOR::BLUE){
                if(current_cube[3][1][1] == COLOR::RED && current_cube[3][2][0] == COLOR::RED && current_cube[3][2][1] == COLOR::RED && current_cube[3][2][2] == COLOR::RED){
                    if(current_cube[5][1][1] == COLOR::ORANGE && current_cube[5][2][0] == COLOR::ORANGE && current_cube[5][2][1] == COLOR::ORANGE && current_cube[5][2][2] == COLOR::ORANGE){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void::Algo::firstLayerSolver(Cube &Cube) {
    COLOR_cube current_cube = Cube.getCube();
    while (!isSolvedFirstLayer(Cube)) {

        //if front side is green
        if(current_cube[5][0][0] == COLOR::WHITE){
            if (current_cube[2][0][2] == COLOR::GREEN && current_cube[0][2][2] == COLOR::ORANGE){
                Cube.Rotate(R);
                Cube.Rotate(U);
                Cube.Rotate(Rprime);
            }
            else if (current_cube[2][0][2] == COLOR::RED && current_cube[0][2][2] == COLOR::GREEN){
                Cube.Rotate(U);
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(Fprime);
            }
            else if (current_cube[2][0][2] == COLOR::BLUE && current_cube[0][2][2] == COLOR::RED){
                Cube.Rotate(U2);
                Cube.Rotate(L);
                Cube.Rotate(U);
                Cube.Rotate(Lprime);
            }
            else if (current_cube[2][0][2] == COLOR::ORANGE && current_cube[0][2][2] == COLOR::BLUE){
                Cube.Rotate(Uprime);
                Cube.Rotate(Bprime);
                Cube.Rotate(U);
                Cube.Rotate(B);
            }
        }

        if (current_cube[2][0][2] == COLOR::WHITE){
            if (current_cube[0][2][2] == COLOR::GREEN && current_cube[5][0][0] == COLOR::ORANGE){
                Cube.Rotate(Fprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(F);
            }
            if (current_cube[0][2][2] == COLOR::RED && current_cube[5][0][0] == COLOR::GREEN){
                Cube.Rotate(U);
                Cube.Rotate(Lprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(L);
            }
            if (current_cube[0][2][2] == COLOR::BLUE && current_cube[5][0][0] == COLOR::RED){
                Cube.Rotate(U2);
                Cube.Rotate(B);
                Cube.Rotate(Uprime);
                Cube.Rotate(Bprime);
            }
            if(current_cube[0][2][2] == COLOR::ORANGE && current_cube[5][0][0] == COLOR::BLUE){
                Cube.Rotate(Uprime);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(R);
            }

        }

        if (current_cube[0][2][2] == COLOR::WHITE){
            Cube.Rotate(R);
            Cube.Rotate(U2);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
        }

        //if front side is red
        if (current_cube[2][0][0] == COLOR::WHITE){
            if (current_cube[3][0][2] == COLOR::RED && current_cube[0][2][0] == COLOR::GREEN){
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(Fprime);
            }
            else if(current_cube[3][0][2] == COLOR::BLUE && current_cube[0][2][0] == COLOR::RED){
                Cube.Rotate(U);
                Cube.Rotate(L);
                Cube.Rotate(U);
                Cube.Rotate(Lprime);
            }
            else if(current_cube[3][0][2] == COLOR::ORANGE && current_cube[0][2][0] == COLOR::BLUE){
                Cube.Rotate(U2);
                Cube.Rotate(B);
                Cube.Rotate(U);
                Cube.Rotate(Bprime);
            }
            else if(current_cube[3][0][2] == COLOR::GREEN && current_cube[0][2][0] == COLOR::ORANGE){
                Cube.Rotate(Uprime);
                Cube.Rotate(R);
                Cube.Rotate(U);
                Cube.Rotate(Rprime);
            }
        }

        if (current_cube[3][0][2] == COLOR::WHITE){
            if (current_cube[0][2][0] == COLOR::RED && current_cube[2][0][0] == COLOR::GREEN){
                Cube.Rotate(Lprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(L);
            }
            else if(current_cube[0][2][0] == COLOR::BLUE && current_cube[2][0][0] == COLOR::RED){
                Cube.Rotate(U);
                Cube.Rotate(B);
                Cube.Rotate(Uprime);
                Cube.Rotate(Bprime);
            }
            else if(current_cube[0][2][0] == COLOR::ORANGE && current_cube[2][0][0] == COLOR::BLUE){
                Cube.Rotate(U2);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(R);
            }
            else if(current_cube[0][2][0] == COLOR::GREEN && current_cube[2][0][0] == COLOR::ORANGE){
                Cube.Rotate(Uprime);
                Cube.Rotate(Fprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(F);
            }
        }

        if(current_cube[0][2][0] == COLOR::WHITE) {
            Cube.Rotate(F);
            Cube.Rotate(U2);
            Cube.Rotate(Fprime);
            Cube.Rotate(Uprime);
        }

        //if front side is blue
        if (current_cube[3][0][0] == COLOR::WHITE){
            if(current_cube[4][0][2] == COLOR::BLUE && current_cube[0][0][0] == COLOR::RED){
                Cube.Rotate(L);
                Cube.Rotate(U);
                Cube.Rotate(Lprime);
            }
            else if(current_cube[4][0][2] == COLOR::ORANGE && current_cube[0][0][0] == COLOR::BLUE){
                Cube.Rotate(U);
                /*Cube.Rotate(Bprime);
                Cube.Rotate(U);
                Cube.Rotate(B);*/
                Cube.Rotate(B);
                Cube.Rotate(U);
                Cube.Rotate(Bprime);
            }
            else if(current_cube[4][0][2] == COLOR::GREEN && current_cube[0][0][0] == COLOR::ORANGE){
                Cube.Rotate(U2);
                Cube.Rotate(R);
                Cube.Rotate(U);
                Cube.Rotate(Rprime);
            }
            else if(current_cube[4][0][2] == COLOR::RED && current_cube[0][0][0] == COLOR::GREEN){
                Cube.Rotate(Uprime);
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(Fprime);
            }
        }

        if (current_cube[4][0][2] == COLOR::WHITE){
            if(current_cube[0][0][0] == COLOR::BLUE && current_cube[3][0][0] == COLOR::RED){
                Cube.Rotate(Bprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(B);
            }
            else if(current_cube[0][0][0] == COLOR::ORANGE && current_cube[3][0][0] == COLOR::BLUE){
                Cube.Rotate(U);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(R);
            }
            else if(current_cube[0][0][0] == COLOR::GREEN && current_cube[3][0][0] == COLOR::ORANGE){
                Cube.Rotate(U2);
                Cube.Rotate(Fprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(F);
            }
            else if(current_cube[0][0][0] == COLOR::RED && current_cube[3][0][0] == COLOR::GREEN){
                Cube.Rotate(Uprime);
                Cube.Rotate(Lprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(L);
            }
        }
        if(current_cube[0][0][0] == COLOR::WHITE){
            Cube.Rotate(L);
            Cube.Rotate(U2);
            Cube.Rotate(Lprime);
            Cube.Rotate(Uprime);

        }
        //if front side is orange

        if(current_cube[4][0][0] == COLOR::WHITE){
            if(current_cube[5][0][2] == COLOR::ORANGE && current_cube[0][0][2] == COLOR::BLUE){
                Cube.Rotate(B);
                Cube.Rotate(U);
                Cube.Rotate(Bprime);
            }
            else if(current_cube[5][0][2] == COLOR::GREEN && current_cube[0][0][2] == COLOR::ORANGE){
                Cube.Rotate(U);
                Cube.Rotate(R);
                Cube.Rotate(U);
                Cube.Rotate(Rprime);
            }
            else if(current_cube[5][0][2] == COLOR::RED && current_cube[0][0][2] == COLOR::GREEN){
                Cube.Rotate(U2);
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(Fprime);
            }
            else if(current_cube[5][0][2] == COLOR::BLUE && current_cube[0][0][2] == COLOR::RED){
                Cube.Rotate(Uprime);
                Cube.Rotate(L);
                Cube.Rotate(U);
                Cube.Rotate(Lprime);
            }
        }

        if(current_cube[5][0][2] == COLOR::WHITE){
            if(current_cube[0][0][2] == COLOR::ORANGE && current_cube[4][0][0] == COLOR::BLUE){
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(R);
            }
            else if(current_cube[0][0][2] == COLOR::GREEN && current_cube[4][0][0] == COLOR::ORANGE){
                Cube.Rotate(U);
                Cube.Rotate(Fprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(F);
            }
            else if(current_cube[0][0][2] == COLOR::RED && current_cube[4][0][0] == COLOR::GREEN){
                Cube.Rotate(U2);
                Cube.Rotate(Lprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(L);
            }
            else if(current_cube[0][0][2] == COLOR::BLUE && current_cube[4][0][0] == COLOR::RED){
                Cube.Rotate(Uprime);
                Cube.Rotate(Bprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(B);
            }
        }
        if(current_cube[0][0][2] == COLOR::WHITE) {
            // if(current_cube[5][0][2] == COLOR::BLUE && current_cube[4][0][0] == COLOR::ORANGE){
            Cube.Rotate(B);
            Cube.Rotate(U2);
            Cube.Rotate(Bprime);
            Cube.Rotate(Uprime);
        }
            //если в верхнем слое не окажется угловых элементов с белым цветом
        else {
            //если углы белой стороны внизу не белые (не на своих местах)
            if (current_cube[1][0][0] != COLOR::WHITE || current_cube[1][0][2] != COLOR::WHITE ||
                current_cube[1][2][0] != COLOR::WHITE || current_cube[1][2][2] != COLOR::WHITE) {
                //if front is green
                if (current_cube[5][2][0] == COLOR::WHITE) {
                    Cube.Rotate(R);
                    Cube.Rotate(U);
                    Cube.Rotate(Rprime);

                }
                    //if front is orange
                else if (current_cube[4][2][0] == COLOR::WHITE) {
                    Cube.Rotate(B);
                    Cube.Rotate(U);
                    Cube.Rotate(Bprime);

                }
                    //if front is blue
                else if (current_cube[3][2][0] == COLOR::WHITE) {
                    Cube.Rotate(L);
                    Cube.Rotate(U);
                    Cube.Rotate(Lprime);

                }
                    //if front is res(pink)
                else if (current_cube[2][2][0] == COLOR::WHITE) {
                    Cube.Rotate(F);
                    Cube.Rotate(U);
                    Cube.Rotate(Fprime);

                }

            }
        }
    }
    //Cube.printCube();
}

void Algo::SetEdge(int fc, Cube& Cube, int ce) {
    if (fc == COLOR::RED) {
        Cube.Rotate(L2);
    }
    else if (fc == COLOR::BLUE) {
        Cube.Rotate(B2);
    }
    else if (fc == COLOR::ORANGE) {
        Cube.Rotate(R2);
    }
    else {
        Cube.Rotate(F2);
    }
}

void Algo::SetEdgeFront(int fc, Cube& Cube, int ce) {
    if (fc == COLOR::GREEN) {
        Cube.Rotate(F);
        Cube.Rotate(Dprime);
        Cube.Rotate(Rprime);
        Cube.Rotate(D);
    }
    else if (fc == COLOR::RED) {
        Cube.Rotate(U);
        Cube.Rotate(Bprime);
        Cube.Rotate(Lprime);
        Cube.Rotate(B);
    }
    else if (fc == COLOR::BLUE) {
        Cube.Rotate(Bprime);
        Cube.Rotate(Dprime);
        Cube.Rotate(Lprime);
        Cube.Rotate(D);
    }
    else {
        Cube.Rotate(R);
        Cube.Rotate(Dprime);
        Cube.Rotate(B);
        Cube.Rotate(D);
    }
}

void Algo::solveBlue(Cube &Cube) {
    COLOR_cube current_cube = Cube.getCube();
    int ce = current_cube[0][0][1];
    int fe = current_cube[4][0][1];
    if (ce != COLOR::YELLOW && fe != COLOR::YELLOW) {
        if (ce == COLOR::RED && fe == COLOR::BLUE) {
            Cube.Rotate(B);
            Cube.Rotate(U);
            Cube.Rotate(B);
            Cube.Rotate(U);
            Cube.Rotate(B);
            Cube.Rotate(Uprime);
            Cube.Rotate(Bprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Bprime);
        }
        else if (ce == COLOR::ORANGE && fe == COLOR::BLUE) {
            Cube.Rotate(Bprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Bprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Bprime);
            Cube.Rotate(U);
            Cube.Rotate(B);
            Cube.Rotate(U);
            Cube.Rotate(B);
        }
    }
}

void Algo::solveRed(Cube &Cube) {
    COLOR_cube current_cube = Cube.getCube();
    int ce = current_cube[0][1][0];
    int fe = current_cube[3][0][1];
    if (ce != COLOR::YELLOW && fe != COLOR::YELLOW) {
        if (ce == COLOR::GREEN && fe == COLOR::RED) {
            Cube.Rotate(L);
            Cube.Rotate(U);
            Cube.Rotate(L);
            Cube.Rotate(U);
            Cube.Rotate(L);
            Cube.Rotate(Uprime);
            Cube.Rotate(Lprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Lprime);
        }
        else if (ce == COLOR::BLUE && fe == COLOR::RED) {
            Cube.Rotate(Lprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Lprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Lprime);
            Cube.Rotate(U);
            Cube.Rotate(L);
            Cube.Rotate(U);
            Cube.Rotate(L);
        }
    }
}

void Algo::solveGreen(Cube &Cube) {
    COLOR_cube current_cube = Cube.getCube();
    int ce = current_cube[0][2][1];
    int fe = current_cube[2][0][1];
    if (ce != COLOR::YELLOW && fe != COLOR::YELLOW) {
        if (ce == COLOR::ORANGE && fe == COLOR::GREEN) {
            Cube.Rotate(F);
            Cube.Rotate(U);
            Cube.Rotate(F);
            Cube.Rotate(U);
            Cube.Rotate(F);
            Cube.Rotate(Uprime);
            Cube.Rotate(Fprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Fprime);
        }
        else if (ce == COLOR::RED && fe == COLOR::GREEN) {
            Cube.Rotate(Fprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Fprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Fprime);
            Cube.Rotate(U);
            Cube.Rotate(F);
            Cube.Rotate(U);
            Cube.Rotate(F);
        }
    }
}

void Algo::solveOrange(Cube &Cube) {
    COLOR_cube current_cube = Cube.getCube();
    int ce = current_cube[0][1][1];
    int fe = current_cube[5][0][1];
    if (ce != COLOR::YELLOW && fe != COLOR::YELLOW) {
        if (ce == COLOR::BLUE && fe == COLOR::ORANGE) {
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(R);
            Cube.Rotate(Uprime);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Rprime);
        }
        else if (ce == COLOR::GREEN && fe == COLOR::ORANGE) {
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Rprime);
            Cube.Rotate(U);
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(R);
        }
    }
}
bool Algo::isSolvedMiddleLayer(COLOR_cube &cube) {
    for (int i = 2; i < 6; i++) {
        if (!(cube[i][1][0] == cube[i][1][1] && cube[i][1][1] == cube[i][1][2])) {
            return false;
        }
        if (!(cube[i][2][0] == cube[i][2][1] && cube[i][2][1] == cube[i][2][2])) {
            return false;
        }
    }
    return true;
}

void Algo::fixWrongSecondLayerEdges(COLOR_cube current_cube, Cube& Cube) {
    if (current_cube[2][1][2] != COLOR::YELLOW && current_cube[5][1][0] != COLOR::YELLOW) {
        Cube.Rotate(U);
        Cube.Rotate(R);
        Cube.Rotate(Uprime);
        Cube.Rotate(Rprime);
        Cube.Rotate(Uprime);
        Cube.Rotate(Fprime);
        Cube.Rotate(U);
        Cube.Rotate(F);
    }
    if (current_cube[5][1][2] != COLOR::YELLOW && current_cube[4][1][0] != COLOR::YELLOW) {
        Cube.Rotate(R);
        Cube.Rotate(U);
        Cube.Rotate(R);
        Cube.Rotate(U);
        Cube.Rotate(R);
        Cube.Rotate(Uprime);
        Cube.Rotate(Rprime);
        Cube.Rotate(Uprime);
        Cube.Rotate(Rprime);
    }
    if (current_cube[4][1][2] != COLOR::YELLOW && current_cube[3][1][0] != COLOR::YELLOW) {
        Cube.Rotate(B);
        Cube.Rotate(U);
        Cube.Rotate(B);
        Cube.Rotate(U);
        Cube.Rotate(B);
        Cube.Rotate(Uprime);
        Cube.Rotate(Bprime);
        Cube.Rotate(Uprime);
        Cube.Rotate(Bprime);
    }
    if (current_cube[3][1][2] != COLOR::YELLOW && current_cube[2][1][0] != COLOR::YELLOW) {
        Cube.Rotate(R);
        Cube.Rotate(U);
        Cube.Rotate(R);
        Cube.Rotate(U);
        Cube.Rotate(R);
        Cube.Rotate(Uprime);
        Cube.Rotate(Rprime);
        Cube.Rotate(Uprime);
        Cube.Rotate(Rprime);
    }
}

void Algo::solveMiddleLayer(Cube& Cube) {
    COLOR_cube current_cube = Cube.getCube();
    //Cube.history.clear();
    while (!isSolvedMiddleLayer(current_cube)) {
        //Cube.printRotations();
        //Cube.history.clear();
        int ce = current_cube[0][0][1];
        int fe = current_cube[4][0][1];
        if (ce != COLOR::YELLOW && fe != COLOR::YELLOW) {
            if (ce == COLOR::RED && fe == COLOR::BLUE) {
                Cube.Rotate(B);
                Cube.Rotate(U);
                Cube.Rotate(B);
                Cube.Rotate(U);
                Cube.Rotate(B);
                Cube.Rotate(Uprime);
                Cube.Rotate(Bprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Bprime);
            }
            else if (ce == COLOR::ORANGE && fe == COLOR::BLUE) {
                Cube.Rotate(Bprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Bprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Bprime);
                Cube.Rotate(U);
                Cube.Rotate(B);
                Cube.Rotate(U);
                Cube.Rotate(B);
            }
            else {
                if (fe == COLOR::RED) {
                    Cube.Rotate(Uprime);
                    solveRed(Cube);
                }
                if (fe == COLOR::GREEN) {
                    Cube.Rotate(U2);
                    solveGreen(Cube);
                }
                if (fe == COLOR::ORANGE) {
                    Cube.Rotate(U);
                    solveOrange(Cube);
                }
            }
        }
        ce = current_cube[0][1][0];
        fe = current_cube[3][0][1];
        if (ce != COLOR::YELLOW && fe != COLOR::YELLOW) {
            if (ce == COLOR::GREEN && fe == COLOR::RED) {
                Cube.Rotate(L);
                Cube.Rotate(U);
                Cube.Rotate(L);
                Cube.Rotate(U);
                Cube.Rotate(L);
                Cube.Rotate(Uprime);
                Cube.Rotate(Lprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Lprime);
            }
            else if (ce == COLOR::BLUE && fe == COLOR::RED) {
                Cube.Rotate(Lprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Lprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Lprime);
                Cube.Rotate(U);
                Cube.Rotate(L);
                Cube.Rotate(U);
                Cube.Rotate(L);
            }
            else {
                if (fe == COLOR::ORANGE) {
                    Cube.Rotate(U2);
                    solveOrange(Cube);
                }
                if (fe == COLOR::GREEN) {
                    Cube.Rotate(Uprime);
                    solveGreen(Cube);
                }
                if (fe == COLOR::BLUE) {
                    Cube.Rotate(U);
                    solveBlue(Cube);
                }
            }
        }
        ce = current_cube[0][2][1];
        fe = current_cube[2][0][1];
        if (ce != COLOR::YELLOW && fe != COLOR::YELLOW) {
            if (ce == COLOR::ORANGE && fe == COLOR::GREEN) {
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(F);
                Cube.Rotate(Uprime);
                Cube.Rotate(Fprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Fprime);
            }
            else if (ce == COLOR::RED && fe == COLOR::GREEN) {
                Cube.Rotate(Fprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Fprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Fprime);
                Cube.Rotate(U);
                Cube.Rotate(F);
                Cube.Rotate(U);
                Cube.Rotate(F);
            }
            else {
                if (fe == COLOR::ORANGE) {
                    Cube.Rotate(Uprime);
                    solveOrange(Cube);
                }
                if (fe == COLOR::RED) {
                    Cube.Rotate(U);
                    solveRed(Cube);
                }
                if (fe == COLOR::BLUE) {
                    Cube.Rotate(U2);
                    solveBlue(Cube);
                }
            }
        }
        ce = current_cube[0][1][2];
        fe = current_cube[5][0][1];
        if (ce != COLOR::YELLOW && fe != COLOR::YELLOW) {
            if (ce == COLOR::BLUE && fe == COLOR::ORANGE) {
                Cube.Rotate(R);
                Cube.Rotate(U);
                Cube.Rotate(R);
                Cube.Rotate(U);
                Cube.Rotate(R);
                Cube.Rotate(Uprime);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Rprime);
            }
            else if (ce == COLOR::GREEN && fe == COLOR::ORANGE) {
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Rprime);
                Cube.Rotate(Uprime);
                Cube.Rotate(Rprime);
                Cube.Rotate(U);
                Cube.Rotate(R);
                Cube.Rotate(U);
                Cube.Rotate(R);
            }
            else {
                if (fe == COLOR::GREEN) {
                    Cube.Rotate(Uprime);
                    solveGreen(Cube);
                }
                if (fe == COLOR::BLUE) {
                    Cube.Rotate(U);
                    solveBlue(Cube);
                }
                if (fe == COLOR::RED) {
                    Cube.Rotate(U2);
                    solveRed(Cube);
                }
            }
        }
        //Cube.printCube();
        if (!isSolvedMiddleLayer(current_cube)) {
            if (current_cube[0][0][1] != COLOR::YELLOW && current_cube[4][0][1] != COLOR::YELLOW) {
                continue;
            }
            else if (current_cube[0][1][2] != COLOR::YELLOW && current_cube[5][0][1] != COLOR::YELLOW) {
                continue;
            }
            else if (current_cube[0][2][1] != COLOR::YELLOW && current_cube[2][0][1] != COLOR::YELLOW) {
                continue;
            }
            else if (current_cube[0][1][0] != COLOR::YELLOW && current_cube[3][0][1] != COLOR::YELLOW) {
                continue;
            }
            else {
                fixWrongSecondLayerEdges(current_cube, Cube);
            }
            //Cube.printRotations();
            //Cube.printCube();
        }
    }
}

bool Algo::isYellowCross(Cube &cube) {
    COLOR_cube current_cube = cube.getCube();
    if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW &&
        current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW) {
        return true;
    }
    return false;
}

void::Algo::solveYellowCross(Cube &Cube) {
    COLOR_cube current_cube = Cube.getCube();
    while(!isYellowCross(Cube)) {
        if(isSolvedMiddleLayer(current_cube)) {

            //if green is front
            if(current_cube[0][1][1] == COLOR::YELLOW) {
                if (current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW &&
                    current_cube[0][1][0] == COLOR::YELLOW) {
                    Cube.Rotate(F);
                    Cube.Rotate(U);
                    Cube.Rotate(R);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Rprime);
                    Cube.Rotate(Fprime);
                }
                else if (current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW &&
                         current_cube[0][1][0] == COLOR::YELLOW) {
                    Cube.Rotate(F);
                    Cube.Rotate(R);
                    Cube.Rotate(U);
                    Cube.Rotate(Rprime);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Fprime);
                }

                //if red(pink) is front
                if (current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW &&
                    current_cube[0][1][2] == COLOR::YELLOW) {
                    Cube.Rotate(L);
                    Cube.Rotate(U);
                    Cube.Rotate(F);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Fprime);
                    Cube.Rotate(Lprime);
                }
                else if (current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW &&
                         current_cube[0][0][1] == COLOR::YELLOW) {
                    Cube.Rotate(L);
                    Cube.Rotate(F);
                    Cube.Rotate(U);
                    Cube.Rotate(Fprime);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Lprime);
                }

                //if blue is front
                if (current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW &&
                    current_cube[0][1][2] == COLOR::YELLOW) {
                    Cube.Rotate(B);
                    Cube.Rotate(U);
                    Cube.Rotate(L);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Lprime);
                    Cube.Rotate(Bprime);
                }
                else if (current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW &&
                         current_cube[0][1][0] == COLOR::YELLOW) {
                    Cube.Rotate(B);
                    Cube.Rotate(L);
                    Cube.Rotate(U);
                    Cube.Rotate(Lprime);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Bprime);
                }

                //if orange is front
                if (current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW &&
                    current_cube[0][1][0] == COLOR::YELLOW) {
                    Cube.Rotate(R);
                    Cube.Rotate(U);
                    Cube.Rotate(B);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Bprime);
                    Cube.Rotate(Rprime);
                }
                else if (current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW &&
                         current_cube[0][0][1] == COLOR::YELLOW) {

                    Cube.Rotate(R);
                    Cube.Rotate(B);
                    Cube.Rotate(U);
                    Cube.Rotate(Bprime);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Rprime);
                }

                else{
                    Cube.Rotate(F);
                    Cube.Rotate(U);
                    Cube.Rotate(R);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Rprime);
                    Cube.Rotate(Fprime);
                }
            }
        }
    }
}

bool Algo::isSolvedYellow(Cube & Cube) {
    COLOR_cube current_cube = Cube.getCube();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (current_cube[0][i][j] != COLOR::YELLOW) {
                return false;
            }
        }
    }
    return true;
}

void Algo::solveYellowFace(Cube &Cube) {
    COLOR_cube current_cube = Cube.getCube();
    if (isSolvedYellow(Cube)) {
        return;
    }

    //pos 1.1 (green)
    if (current_cube[0][0][0] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][0][2] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW &&
            current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][2][1] == COLOR::YELLOW && current_cube[2][0][0] == COLOR::YELLOW && current_cube[2][0][2] == COLOR::YELLOW) {
                Cube.Rotate(R2);
                Cube.Rotate(D);
                Cube.Rotate(Rprime);
                Cube.Rotate(U2);
                Cube.Rotate(R);
                Cube.Rotate(Dprime);
                Cube.Rotate(Rprime);
                Cube.Rotate(U2);
                Cube.Rotate(Rprime);
                return;
            }
        }
    }

    //pos 1.2 (red)
    if (current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][2] == COLOR::YELLOW && current_cube[0][0][2] == COLOR::YELLOW) {
        if (current_cube[0][2][1] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW &&
            current_cube[0][0][1] == COLOR::YELLOW) {
            if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[3][0][0] == COLOR::YELLOW && current_cube[3][0][2] == COLOR::YELLOW) {
                Cube.Rotate(F2);
                Cube.Rotate(D);
                Cube.Rotate(Fprime);
                Cube.Rotate(U2);
                Cube.Rotate(F);
                Cube.Rotate(Dprime);
                Cube.Rotate(Fprime);
                Cube.Rotate(U2);
                Cube.Rotate(Fprime);
                return;
            }
        }
    }

    //pos 1.3 (blue)
    if (current_cube[0][2][0] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW && current_cube[0][2][2] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW &&
            current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[4][0][0] == COLOR::YELLOW && current_cube[4][0][2] == COLOR::YELLOW) {
                Cube.Rotate(L2);
                Cube.Rotate(D);
                Cube.Rotate(Lprime);
                Cube.Rotate(U2);
                Cube.Rotate(L);
                Cube.Rotate(Dprime);
                Cube.Rotate(Lprime);
                Cube.Rotate(U2);
                Cube.Rotate(Lprime);
                return;
            }
        }
    }

    // pos 1.4 (orange)
    if (current_cube[0][0][0] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][2][0] == COLOR::YELLOW) {
        if (current_cube[0][2][1] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW &&
            current_cube[0][0][1] == COLOR::YELLOW) {
            if (current_cube[0][1][2] == COLOR::YELLOW && current_cube[2][0][0] == COLOR::YELLOW && current_cube[2][0][2] == COLOR::YELLOW) {
                Cube.Rotate(B2);
                Cube.Rotate(D);
                Cube.Rotate(Bprime);
                Cube.Rotate(U2);
                Cube.Rotate(B);
                Cube.Rotate(Dprime);
                Cube.Rotate(Bprime);
                Cube.Rotate(U2);
                Cube.Rotate(Bprime);
                return;
            }
        }
    }

    //pow 2.1
    if (current_cube[0][0][0] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][2][0] == COLOR::YELLOW) {
        if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
            if (current_cube[0][1][2] == COLOR::YELLOW && current_cube[4][0][0] == COLOR::YELLOW && current_cube[2][0][2] == COLOR::YELLOW) {
                Cube.Rotate(Rprime);
                Cube.Rotate(Fprime);
                Cube.Rotate(L);
                Cube.Rotate(F);
                Cube.Rotate(R);
                Cube.Rotate(Fprime);
                Cube.Rotate(Lprime);
                Cube.Rotate(F);
                return;
            }
        }
    }

    //pos 2.2 (red)
    if (current_cube[0][0][0] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][0][2] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][2][1] == COLOR::YELLOW && current_cube[5][0][0] == COLOR::YELLOW && current_cube[3][0][2] == COLOR::YELLOW) {
                Cube.Rotate(Fprime);
                Cube.Rotate(Lprime);
                Cube.Rotate(B);
                Cube.Rotate(L);
                Cube.Rotate(F);
                Cube.Rotate(Lprime);
                Cube.Rotate(Bprime);
                Cube.Rotate(L);
                return;
            }
        }
    }

    //pos 2.3 (blue)
    if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
        if (current_cube[0][0][2] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][2] == COLOR::YELLOW) {
            if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[2][0][0] == COLOR::YELLOW && current_cube[4][0][2] == COLOR::YELLOW) {
                Cube.Rotate(Lprime);
                Cube.Rotate(Bprime);
                Cube.Rotate(R);
                Cube.Rotate(B);
                Cube.Rotate(L);
                Cube.Rotate(Bprime);
                Cube.Rotate(Rprime);
                Cube.Rotate(B);
                return;
            }
        }
    }

    //pos 2.4 (orange)
    if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW) {
        if (current_cube[0][2][1] == COLOR::YELLOW && current_cube[0][2][0] == COLOR::YELLOW && current_cube[0][2][2] == COLOR::YELLOW) {
            if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[3][0][0] == COLOR::YELLOW && current_cube[5][0][2] == COLOR::YELLOW) {
                Cube.Rotate(Bprime);
                Cube.Rotate(Rprime);
                Cube.Rotate(F);
                Cube.Rotate(R);
                Cube.Rotate(B);
                Cube.Rotate(Rprime);
                Cube.Rotate(Fprime);
                Cube.Rotate(R);
                return;
            }
        }
    }

    //pos 3.1
    if (current_cube[0][0][0] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][2][1] == COLOR::YELLOW && current_cube[0][2][2] == COLOR::YELLOW) {
                if (current_cube[4][0][0] == COLOR::YELLOW && current_cube[3][0][2] == COLOR::YELLOW) {
                    Cube.Rotate(Rprime);
                    Cube.Rotate(Fprime);
                    Cube.Rotate(Lprime);
                    Cube.Rotate(F);
                    Cube.Rotate(R);
                    Cube.Rotate(Fprime);
                    Cube.Rotate(L);
                    Cube.Rotate(F);
                    return;
                }
            }
        }
    }

    //pos 3.2
    if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][0][2] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][2][0] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
                if (current_cube[5][0][0] == COLOR::YELLOW && current_cube[4][0][2] == COLOR::YELLOW) {
                    Cube.Rotate(Fprime);
                    Cube.Rotate(Lprime);
                    Cube.Rotate(Bprime);
                    Cube.Rotate(L);
                    Cube.Rotate(F);
                    Cube.Rotate(Lprime);
                    Cube.Rotate(B);
                    Cube.Rotate(L);
                    return;
                }
            }
        }
    }

    //pos 3.3.
    if (current_cube[0][0][0] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][2][1] == COLOR::YELLOW && current_cube[0][2][2] == COLOR::YELLOW) {
                if (current_cube[2][0][0] == COLOR::YELLOW && current_cube[5][0][2] == COLOR::YELLOW) {
                    Cube.Rotate(Lprime);
                    Cube.Rotate(Bprime);
                    Cube.Rotate(Rprime);
                    Cube.Rotate(B);
                    Cube.Rotate(L);
                    Cube.Rotate(Bprime);
                    Cube.Rotate(R);
                    Cube.Rotate(B);
                    return;
                }
            }
        }
    }

    //pos 3.4
    if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][0][2] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][2][0] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
                if (current_cube[2][0][2] == COLOR::YELLOW && current_cube[3][0][0] == COLOR::YELLOW) {
                    Cube.Rotate(Bprime);
                    Cube.Rotate(Rprime);
                    Cube.Rotate(Fprime);
                    Cube.Rotate(R);
                    Cube.Rotate(B);
                    Cube.Rotate(Rprime);
                    Cube.Rotate(F);
                    Cube.Rotate(R);
                    return;
                }
            }
        }
    }

    //pos 4.1 (green)
    if (current_cube[0][0][1] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][2][0] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
                if (current_cube[4][0][2] == COLOR::YELLOW && current_cube[5][0][2] == COLOR::YELLOW && current_cube[2][0][2] == COLOR::YELLOW) {
                    Cube.Rotate(R);
                    Cube.Rotate(U);
                    Cube.Rotate(Rprime);
                    Cube.Rotate(U);
                    Cube.Rotate(R);
                    Cube.Rotate(U2);
                    Cube.Rotate(Rprime);
                    return;
                }
            }
        }
    }

    //pos 4.2 (red)
    if (current_cube[0][1][2] == COLOR::YELLOW) {
        if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
            if (current_cube[0][0][0] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW) {
                if (current_cube[3][0][2] == COLOR::YELLOW && current_cube[5][0][2] == COLOR::YELLOW && current_cube[2][0][2] == COLOR::YELLOW) {
                    Cube.Rotate(F);
                    Cube.Rotate(U);
                    Cube.Rotate(Fprime);
                    Cube.Rotate(U);
                    Cube.Rotate(F);
                    Cube.Rotate(U2);
                    Cube.Rotate(Fprime);
                    return;
                }
            }
        }
    }

    //pos 4.3 (blue)
    if (current_cube[0][2][1] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][0][2] == COLOR::YELLOW) {
                if (current_cube[4][0][2] == COLOR::YELLOW && current_cube[3][0][2] == COLOR::YELLOW && current_cube[2][0][2] == COLOR::YELLOW) {
                    Cube.Rotate(L);
                    Cube.Rotate(U);
                    Cube.Rotate(Lprime);
                    Cube.Rotate(U);
                    Cube.Rotate(L);
                    Cube.Rotate(U2);
                    Cube.Rotate(Lprime);
                    return;
                }
            }
        }
    }

    //pos 4.4 (orange)
    if (current_cube[0][1][0] == COLOR::YELLOW) {
        if (current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
            if (current_cube[0][2][2] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
                if (current_cube[4][0][2] == COLOR::YELLOW && current_cube[5][0][2] == COLOR::YELLOW && current_cube[3][0][2] == COLOR::YELLOW) {
                    Cube.Rotate(B);
                    Cube.Rotate(U);
                    Cube.Rotate(Bprime);
                    Cube.Rotate(U);
                    Cube.Rotate(B);
                    Cube.Rotate(U2);
                    Cube.Rotate(Bprime);
                    return;
                }
            }
        }
    }

    //pos 5.1 (green)
    if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][0][2] == COLOR::YELLOW) {
        if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW) {
            if (current_cube[0][2][1] == COLOR::YELLOW) {
                if (current_cube[3][0][0] == COLOR::YELLOW && current_cube[2][0][0] == COLOR::YELLOW && current_cube[5][0][0] == COLOR::YELLOW) {
                    Cube.Rotate(R);
                    Cube.Rotate(U2);
                    Cube.Rotate(Rprime);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(R);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Rprime);
                    return;
                }
            }
        }
    }
    //pos 5.2 (red)
    if (current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][2] == COLOR::YELLOW) {
        if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
            if (current_cube[0][1][0] == COLOR::YELLOW) {
                if (current_cube[3][0][0] == COLOR::YELLOW && current_cube[2][0][0] == COLOR::YELLOW && current_cube[4][0][0] == COLOR::YELLOW) {
                    Cube.Rotate(F);
                    Cube.Rotate(U2);
                    Cube.Rotate(Fprime);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(F);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Fprime);
                    return;
                }
            }
        }
    }
    //pos 5.3 (blue)
    if (current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][2][0] == COLOR::YELLOW) {
        if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
            if (current_cube[0][1][2] == COLOR::YELLOW) {
                if (current_cube[4][0][0] == COLOR::YELLOW && current_cube[3][0][0] == COLOR::YELLOW && current_cube[5][0][0] == COLOR::YELLOW) {
                    Cube.Rotate(L);
                    Cube.Rotate(U2);
                    Cube.Rotate(Lprime);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(L);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Lprime);
                    return;
                }
            }
        }
    }
    //pos 5.4 (orange)
    if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][0][0] == COLOR::YELLOW) {
        if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
            if (current_cube[0][2][1] == COLOR::YELLOW) {
                if (current_cube[4][0][0] == COLOR::YELLOW && current_cube[2][0][0] == COLOR::YELLOW && current_cube[5][0][0] == COLOR::YELLOW) {
                    Cube.Rotate(B);
                    Cube.Rotate(U2);
                    Cube.Rotate(Bprime);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(B);
                    Cube.Rotate(Uprime);
                    Cube.Rotate(Bprime);
                    return;
                }
            }
        }
    }
    //pos 6.1
    if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
        if (current_cube[3][0][2] == COLOR::YELLOW && current_cube[3][0][0] == COLOR::YELLOW && current_cube[2][0][2] == COLOR::YELLOW && current_cube[4][0][0] == COLOR::YELLOW) {
            Cube.Rotate(R);
            Cube.Rotate(U2);
            Cube.Rotate(R2);
            Cube.Rotate(Uprime);
            Cube.Rotate(R2);
            Cube.Rotate(Uprime);
            Cube.Rotate(R2);
            Cube.Rotate(U2);
            Cube.Rotate(R);
            return;
        }
    }
    //red is front 6.2
    if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
        if (current_cube[4][0][0] == COLOR::YELLOW && current_cube[4][0][2] == COLOR::YELLOW && current_cube[3][0][2] == COLOR::YELLOW && current_cube[5][0][0] == COLOR::YELLOW) {
            Cube.Rotate(F);
            Cube.Rotate(U2);
            Cube.Rotate(F2);
            Cube.Rotate(Uprime);
            Cube.Rotate(F2);
            Cube.Rotate(Uprime);
            Cube.Rotate(F2);
            Cube.Rotate(U2);
            Cube.Rotate(F);
            return;
        }
    }

    //6.3, (back is front)
    if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
        if (current_cube[5][0][0] == COLOR::YELLOW && current_cube[5][0][2] == COLOR::YELLOW && current_cube[2][0][0] == COLOR::YELLOW && current_cube[4][0][2] == COLOR::YELLOW) {
            Cube.Rotate(L);
            Cube.Rotate(U2);
            Cube.Rotate(L2);
            Cube.Rotate(Uprime);
            Cube.Rotate(L2);
            Cube.Rotate(Uprime);
            Cube.Rotate(L2);
            Cube.Rotate(U2);
            Cube.Rotate(L);
            return;
        }
    }

    //6.4
    if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
        if (current_cube[2][0][0] == COLOR::YELLOW && current_cube[2][0][2] == COLOR::YELLOW && current_cube[3][0][0] == COLOR::YELLOW && current_cube[5][0][2] == COLOR::YELLOW) {
            Cube.Rotate(B);
            Cube.Rotate(U2);
            Cube.Rotate(B2);
            Cube.Rotate(Uprime);
            Cube.Rotate(B2);
            Cube.Rotate(Uprime);
            Cube.Rotate(B2);
            Cube.Rotate(U2);
            Cube.Rotate(B);
            return;
        }
    }

    //7.1
    if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
        if (current_cube[4][0][0] == COLOR::YELLOW && current_cube[4][0][2] == COLOR::YELLOW && current_cube[2][0][0] == COLOR::YELLOW && current_cube[2][0][2] == COLOR::YELLOW) {
            Cube.Rotate(R);
            Cube.Rotate(U2);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(R);
            Cube.Rotate(Uprime);
            Cube.Rotate(Rprime);
            return;
        }
    }
    //7.2 (red is front)
    if (current_cube[0][0][1] == COLOR::YELLOW && current_cube[0][1][0] == COLOR::YELLOW && current_cube[0][1][1] == COLOR::YELLOW && current_cube[0][1][2] == COLOR::YELLOW && current_cube[0][2][1] == COLOR::YELLOW) {
        if (current_cube[3][0][0] == COLOR::YELLOW && current_cube[3][0][2] == COLOR::YELLOW && current_cube[5][0][0] == COLOR::YELLOW && current_cube[5][0][2] == COLOR::YELLOW) {
            Cube.Rotate(F);
            Cube.Rotate(U2);
            Cube.Rotate(Fprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(F);
            Cube.Rotate(U);
            Cube.Rotate(Fprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(F);
            Cube.Rotate(Uprime);
            Cube.Rotate(Fprime);
            return;
        }
    }
}

int::Algo::maxCornersSum(Cube& Cube){
    COLOR_cube current_cube = Cube.getCube();
    int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;
    //if front is green
    if (current_cube[2][0][2] == COLOR::GREEN && current_cube[2][0][0] == COLOR::GREEN){
        counter1 += 2;
    }
    else if (current_cube[2][0][0] == COLOR::GREEN || current_cube[2][0][2] == COLOR::GREEN){
        counter1 += 1;
    }
    if (current_cube[5][0][2] == COLOR::ORANGE && current_cube[5][0][0] == COLOR::ORANGE){
        counter1 += 2;
    }
    else if(current_cube[5][0][0] == COLOR::ORANGE || current_cube[5][0][2] == COLOR::ORANGE){
        counter1 += 1;
    }
    if (current_cube[5][0][2] == COLOR::BLUE && current_cube[5][0][0] == COLOR::BLUE){
        counter1+=2;
    }
    else if (current_cube[5][0][0] == COLOR::BLUE || current_cube[5][0][2] == COLOR::BLUE){
        counter1+=1;
    }
    if (current_cube[3][0][2] == COLOR::RED && current_cube[3][0][0] == COLOR::RED){
        counter1 += 2;
    }
    else if(current_cube[3][0][0] == COLOR::RED || current_cube[3][0][2] == COLOR::RED){
        counter1 += 1;
    }
    else {
        counter1 = 0;
    }

    Cube.Rotate(U);
    //if front is green
    if(current_cube[2][0][2] == COLOR::GREEN && current_cube[2][0][0] == COLOR::GREEN){
        counter2+=2;
    }
    else if(current_cube[2][0][0] == COLOR::GREEN || current_cube[2][0][2] == COLOR::GREEN){
        counter2+=1;
    }
    if(current_cube[5][0][2] == COLOR::ORANGE && current_cube[5][0][0] == COLOR::ORANGE){
        counter2+=2;
    }
    else if(current_cube[5][0][0] == COLOR::ORANGE || current_cube[5][0][2] == COLOR::ORANGE){
        counter2+=1;
    }
    if(current_cube[5][0][2] == COLOR::BLUE && current_cube[5][0][0] == COLOR::BLUE){
        counter2+=2;
    }
    else if(current_cube[5][0][0] == COLOR::BLUE || current_cube[5][0][2] == COLOR::BLUE){
        counter2+=1;
    }
    if(current_cube[3][0][2] == COLOR::RED && current_cube[3][0][0] == COLOR::RED){
        counter2+=2;
    }
    else if(current_cube[3][0][0] == COLOR::RED || current_cube[3][0][2] == COLOR::RED){
        counter2+=1;
    }
    else{
        counter2 = 0;
    }

    Cube.Rotate(U);
    //if front is green

    if(current_cube[2][0][2] == COLOR::GREEN && current_cube[2][0][0] == COLOR::GREEN){
        counter3+=2;
    }
    else if(current_cube[2][0][0] == COLOR::GREEN || current_cube[2][0][2] == COLOR::GREEN){
        counter3+=1;
    }
    if(current_cube[5][0][2] == COLOR::ORANGE && current_cube[5][0][0] == COLOR::ORANGE){
        counter3+=2;
    }
    else if(current_cube[5][0][0] == COLOR::ORANGE || current_cube[5][0][2] == COLOR::ORANGE){
        counter3+=1;
    }
    if(current_cube[5][0][2] == COLOR::BLUE && current_cube[5][0][0] == COLOR::BLUE){
        counter3+=2;
    }
    else if(current_cube[5][0][0] == COLOR::BLUE || current_cube[5][0][2] == COLOR::BLUE){
        counter3+=1;
    }
    if(current_cube[3][0][2] == COLOR::RED && current_cube[3][0][0] == COLOR::RED){
        counter3+=2;
    }
    else if(current_cube[3][0][0] == COLOR::RED || current_cube[3][0][2] == COLOR::RED){
        counter3+=1;
    }
    else{
        counter3 = 0;
    }

    Cube.Rotate(U);
    //if front is green
    if(current_cube[2][0][2] == COLOR::GREEN && current_cube[2][0][0] == COLOR::GREEN){
        counter4 += 2;
    }
    else if(current_cube[2][0][0] == COLOR::GREEN || current_cube[2][0][2] == COLOR::GREEN){
        counter4 += 1;
    }
    if(current_cube[5][0][2] == COLOR::ORANGE && current_cube[5][0][0] == COLOR::ORANGE){
        counter4 += 2;
    }
    else if(current_cube[5][0][0] == COLOR::ORANGE || current_cube[5][0][2] == COLOR::ORANGE){
        counter4+=1;
    }
    if(current_cube[5][0][2] == COLOR::BLUE && current_cube[5][0][0] == COLOR::BLUE){
        counter4 += 2;
    }
    else if(current_cube[5][0][0] == COLOR::BLUE || current_cube[5][0][2] == COLOR::BLUE){
        counter4 += 1;
    }
    if(current_cube[3][0][2] == COLOR::RED && current_cube[3][0][0] == COLOR::RED){
        counter4 += 2;
    }
    else if(current_cube[3][0][0] == COLOR::RED || current_cube[3][0][2] == COLOR::RED){
        counter4 += 1;
    }
    else{
        counter4 = 0;
    }
    Cube.Rotate(U);
    int maximum = std::max(std::max(std::max(counter1,counter2), counter3), counter4);
    if (maximum == counter1){
        return 1;
    }
    else if (maximum == counter2){
        return 2;
    }
    else if (maximum == counter3){
        return 3;
    }
    else {
        return 4;
    }
}

bool::Algo::highCornersCorrectPos(Cube& Cube){
    COLOR_cube current_cube = Cube.getCube();
    if(current_cube[2][1][1] == COLOR::GREEN &&current_cube[2][0][0] == COLOR::GREEN && current_cube[2][0][2] == COLOR::GREEN){
        if(current_cube[5][1][1] == COLOR::ORANGE &&current_cube[5][0][0] == COLOR::ORANGE && current_cube[5][0][2] == COLOR::ORANGE){
            if(current_cube[3][1][1] == COLOR::RED &&current_cube[3][0][0] == COLOR::RED && current_cube[3][0][2] == COLOR::RED){
                if(current_cube[4][1][1] == COLOR::BLUE &&current_cube[4][0][0] == COLOR::BLUE && current_cube[4][0][2] == COLOR::BLUE){
                    return true;
                }
            }
        }
    }
    return false;
}

void::Algo::solveCornerCubies(Cube& Cube){
    COLOR_cube current_cube = Cube.getCube();
    std::vector<std::string> history = Cube.getHistory();
    //if(Max_corners_sum(Cube) == 1){
    //   Cube.Rotate(U);
    //}
    if (maxCornersSum(Cube) == 2){
        Cube.Rotate(U);
    }
    else if(maxCornersSum(Cube) == 3){
        Cube.Rotate(U);
        Cube.Rotate(U);
    }
    else if(maxCornersSum(Cube) == 4){
        Cube.Rotate(U);
        Cube.Rotate(U);
        Cube.Rotate(U);
    }
    //history.clear();
    //Cube.printCube();
    while(!highCornersCorrectPos(Cube)){
        //Cube.printRotations();
        //Cube.printCube();
        //1.1 со стороны green
        if (current_cube[2][0][2] == COLOR::BLUE && current_cube[4][0][0] == COLOR::GREEN){//а не зел, гол, зел? тогда может еще противополож центр в условие дописать(ту то есть про голубой)
            Cube.Rotate(R);
            Cube.Rotate(U2);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(R);
            Cube.Rotate(U2);
            Cube.Rotate(Lprime);
            Cube.Rotate(U);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(L);
        }
        //1.3 со стороны orange
        if (current_cube[5][0][2] == COLOR::RED && current_cube[3][0][0] == COLOR::ORANGE){
            Cube.Rotate(B);
            Cube.Rotate(U2);
            Cube.Rotate(Bprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(B);
            Cube.Rotate(U2);
            Cube.Rotate(Fprime);
            Cube.Rotate(U);
            Cube.Rotate(Bprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(F);
        }
        if (current_cube[4][0][2] == COLOR::GREEN && current_cube[2][0][0] == COLOR::BLUE){
            Cube.Rotate(L);
            Cube.Rotate(U2);
            Cube.Rotate(Lprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(L);
            Cube.Rotate(U2);
            Cube.Rotate(Rprime);
            Cube.Rotate(U);
            Cube.Rotate(Lprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(R);
        }
        //2.1
        if (current_cube[5][0][2] == COLOR::ORANGE && current_cube[3][0][2] == COLOR::RED){
            Cube.Rotate(Lprime);
            Cube.Rotate(U);
            Cube.Rotate(R);
            Cube.Rotate(Uprime);
            Cube.Rotate(L);
            Cube.Rotate(U);
            Cube.Rotate(Lprime);
            Cube.Rotate(U);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(L);
            Cube.Rotate(U2);
            Cube.Rotate(R);
            Cube.Rotate(U2);
            Cube.Rotate(Rprime);
        }
        //со стороны red, 1.2
        if (current_cube[3][0][2] == COLOR::ORANGE && current_cube[5][0][0] == COLOR::RED){
            Cube.Rotate(F);
            Cube.Rotate(U2);
            Cube.Rotate(Fprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(F);
            Cube.Rotate(U2);
            Cube.Rotate(Bprime);
            Cube.Rotate(U);
            Cube.Rotate(Fprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(B);
        }
        if (current_cube[2][0][2] != COLOR::GREEN){
            Cube.Rotate(R);
            Cube.Rotate(U2);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(R);
            Cube.Rotate(U2);
            Cube.Rotate(Lprime);
            Cube.Rotate(U);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(L);
        }
        if (current_cube[2][0][0] != COLOR::GREEN){
            Cube.Rotate(L);
            Cube.Rotate(U2);
            Cube.Rotate(Lprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(L);
            Cube.Rotate(U2);
            Cube.Rotate(Rprime);
            Cube.Rotate(U);
            Cube.Rotate(Lprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(R);
        }
        if (current_cube[5][0][2] != COLOR::ORANGE){
            Cube.Rotate(B);
            Cube.Rotate(U2);
            Cube.Rotate(Bprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(B);
            Cube.Rotate(U2);
            Cube.Rotate(Fprime);
            Cube.Rotate(U);
            Cube.Rotate(Bprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(F);
        }
    }

}

bool Algo::areEdgesSolved(Cube &Cube) {
    COLOR_cube current_cube = Cube.getCube();
    if (current_cube[2][0][1] == COLOR::GREEN && current_cube[3][0][1] == COLOR::RED
        && current_cube[4][0][1] == COLOR::BLUE && current_cube[5][0][1] == COLOR::ORANGE) {
        return true;
    }
    return false;
}

void::Algo::solveEdges(Cube& Cube){
    COLOR_cube current_cube = Cube.getCube();
    while (!areEdgesSolved(Cube)) {
        if (current_cube[3][0][1] == COLOR::BLUE && current_cube[4][0][1] == COLOR::RED && current_cube[2][0][1] == COLOR::ORANGE && current_cube[5][0][1] == COLOR::GREEN){
            Cube.Rotate(R);
            Cube.Rotate(Bprime);
            Cube.Rotate(Rprime);
            Cube.Rotate(B);
            Cube.Rotate(F);
            Cube.Rotate(Rprime);
            Cube.Rotate(Bprime);
            Cube.Rotate(F);
            Cube.Rotate(Rprime);
            Cube.Rotate(B);
            Cube.Rotate(R);
            Cube.Rotate(F);
            Cube.Rotate(F);
            Cube.Rotate(U);
        }
        else if (current_cube[5][0][1] == COLOR::BLUE && current_cube[4][0][1] == COLOR::ORANGE && current_cube[2][0][1] == COLOR::RED && current_cube[3][0][1] == COLOR::GREEN){
            Cube.Rotate(F);
            Cube.Rotate(Rprime);
            Cube.Rotate(Fprime);
            Cube.Rotate(R);
            Cube.Rotate(L);
            Cube.Rotate(Fprime);
            Cube.Rotate(Rprime);
            Cube.Rotate(L);
            Cube.Rotate(Fprime);
            Cube.Rotate(R);
            Cube.Rotate(F);
            Cube.Rotate(L2);
            Cube.Rotate(U);
        }
        else if (current_cube[3][0][1] == COLOR::ORANGE && current_cube[5][0][1] == COLOR::RED && current_cube[2][0][1] == COLOR::BLUE && current_cube[4][0][1] == COLOR::GREEN){
            Cube.Rotate(R2);
            Cube.Rotate(L2);
            Cube.Rotate(D);
            Cube.Rotate(R2);
            Cube.Rotate(L2);
            Cube.Rotate(U2);
            Cube.Rotate(R2);
            Cube.Rotate(L2);
            Cube.Rotate(D);
            Cube.Rotate(R2);
            Cube.Rotate(L2);
        }
        else if (current_cube[3][0][1] != COLOR::RED && current_cube[2][0][1] != COLOR::GREEN && current_cube[5][0][1] != COLOR::ORANGE){
            Cube.Rotate(R2);
            Cube.Rotate(U);
            Cube.Rotate(R);
            Cube.Rotate(U);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Rprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Rprime);
            Cube.Rotate(U);
            Cube.Rotate(Rprime);
        }
        else if (current_cube[4][0][1] != COLOR::BLUE && current_cube[3][0][1] != COLOR::RED && current_cube[5][0][1] != COLOR::ORANGE){
            Cube.Rotate(L);
            Cube.Rotate(Uprime);
            Cube.Rotate(L);
            Cube.Rotate(U);
            Cube.Rotate(L);
            Cube.Rotate(U);
            Cube.Rotate(L);
            Cube.Rotate(Uprime);
            Cube.Rotate(Lprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(L2);
        }
        else if (current_cube[3][0][1] != COLOR::RED && current_cube[2][0][1] != COLOR::GREEN && current_cube[4][0][1] != COLOR::BLUE){
            Cube.Rotate(F2);
            Cube.Rotate(U);
            Cube.Rotate(F);
            Cube.Rotate(U);
            Cube.Rotate(Fprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Fprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Fprime);
            Cube.Rotate(U);
            Cube.Rotate(Fprime);
        }
        else if (current_cube[5][0][1] != COLOR::ORANGE && current_cube[2][0][1] != COLOR::GREEN && current_cube[4][0][1] != COLOR::BLUE){
            Cube.Rotate(B2);
            Cube.Rotate(U);
            Cube.Rotate(B);
            Cube.Rotate(U);
            Cube.Rotate(Bprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Bprime);
            Cube.Rotate(Uprime);
            Cube.Rotate(Bprime);
            Cube.Rotate(U);
            Cube.Rotate(Bprime);
        }
    }
}
