#include "CollisionResponse.h"



CollisionResponse::CollisionResponse(CollisionManager* cm, GameEvents* ge){
	this->cm = cm;
	this->ge = ge;
}


CollisionResponse::~CollisionResponse()
{
}
void CollisionResponse::destroy() {

}

void CollisionResponse::init() {

}

// collision response is responsible for the logic in sorting the collision events into 
// seperate lists for all the different managers to deal with in their own ways
void CollisionResponse::update(float msec) {
	
	// clear lists from last frame
	ge->clearEvents(ge->COLLISIONS);

	for (int i = 0; i < cm->collisions_this_frame.size(); i++){
		if (cm->collisions_this_frame[i].first->group == "snooker_balls") {

			// cueball-pocket
			if (cm->collisions_this_frame[i].first->name == "white" && cm->collisions_this_frame[i].second->group == "pocket_plane") {
				ge->cols_cue_pocket.push_back(pair<Entity*, Entity*>(cm->collisions_this_frame[i].first, cm->collisions_this_frame[i].second));
			}
			// circle-circle
			else if (cm->collisions_this_frame[i].second->group == "snooker_balls"){
				ge->cols_circle_circle.push_back(pair<Entity*, Entity*>(cm->collisions_this_frame[i].first, cm->collisions_this_frame[i].second));

			}
			// circle-cushion
			else if (cm->collisions_this_frame[i].second->group == "cushion_plane") {
				ge->cols_circle_cushion.push_back(pair<Entity*, Entity*>(cm->collisions_this_frame[i].first, cm->collisions_this_frame[i].second));

			}
			// circle-pocket
			else if (cm->collisions_this_frame[i].second->group == "pocket_plane") {
				ge->cols_circle_pocket.push_back(pair<Entity*, Entity*>(cm->collisions_this_frame[i].first, cm->collisions_this_frame[i].second));

			}
		}
	}

}