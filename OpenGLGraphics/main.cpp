#include "Renderer.h"
#include "RenderObject.h"
#include <cmath>
#pragma comment(lib, "nclgl.lib")



void main(void) {
	Window w = Window(800, 600);
	Renderer r(w);

	
	while(w.UpdateWindow()) {
		
		float msec = w.GetTimer()->GetTimedMS();

		r.UpdateScene(msec);
		r.ClearBuffers();
		r.RenderScene();
		r.SwapBuffers();
	}
	
}