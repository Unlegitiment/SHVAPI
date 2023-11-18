#include "script.h"
#include "keyboard.h"
#include "Markers.h"
#include "UI.h"
#include "Scaleform.h"
#include <string>
#include <ctime>

#pragma warning(disable : 4244 4305) // double <-> float conversions

float square(float num) { return num * num; }
float distanceTo(Vector3 vec1, Vector3 vec2) {
    float xsub, ysub, zsub;
    xsub = vec2.x - vec1.x;
    ysub = vec2.y - vec1.y;
    zsub = vec2.z - vec1.z;
    float xsq, ysq, zsq;
    xsq = square(xsub);
    ysq = square(ysub);
    zsq = square(zsub);
    float tot = xsq + ysq + zsq;
    return (float)sqrt(tot);
}
float distanceTo(float x1, float y1, float z1, float x2,float y2, float z2) {
    float xsub, ysub, zsub;
    xsub = x2 - x1;
    ysub = y2 - y1;
    zsub = z2 - z1;
    float xsq, ysq, zsq;
    xsq = square(xsub);
    ysq = square(ysub);
    zsq = square(zsub);
    float tot = xsq + ysq + zsq;
    return (float)sqrt(tot);
}
float distanceTo(Vector3 vec1) {
    Vector3 vec2 = { 0,0,0 };
    float xsub, ysub, zsub;
    xsub = vec2.x - vec1.x;
    ysub = vec2.y - vec1.y;
    zsub = vec2.z - vec1.z;
    float xsq, ysq, zsq;
    xsq = square(xsub);
    ysq = square(ysub);
    zsq = square(zsub);
    float tot = xsq + ysq + zsq;
    return (float)sqrt(tot);
}
#define CHARZ "CHAR_ALL_PLAYERS_CONF"
void main()
{
    // Ticks. 
    while (true)
    {
       if (IsKeyJustUp(VK_DIVIDE)) {   
           /*
           * StartRep = CurrentRepLocation
           * CurrentRank = the Rank You're Currently on
           * NextRank can be really anything you want both can however ideally it'd be CurrentRank+1
           * rpToNext = the nessicary rp to the next rank
           * minNext = if minNext > maxNext rpBar fills completely; if minNext < maxNext completely empty. if minNext == startRep+rpGain 1 bar gets filled
           * minNext is Better put as a 0. Because this reveals the animation and makes it more seemless.
           * maxNext = Represents the Maximum amount the bar can represent. It will trigger an animation extension if it goes past it.
           */
           HeistCelebHandle* handle = EX_HC_FAILED(500, 99, 100,0, 2000, 200, 1500, 20);
       }
        WAIT(0);
    }
}

void ScriptMain()
{
    srand(GetTickCount());
    main();
}
