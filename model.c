    
#include "model.h"
#include "defs.h"
#include "events.h"

void initModel(GameModel *model) {
    int i;
    model->player.x = 320; 
    model->player.y = 200; 
    
    model->player.dy = 0;
    model->player.lives = 3; 
    model->player.score = 0;
    model->game_running = true;
    model->isMuted = true;

    /* default x direction*/
    model->player.speed = 4;
    model->player.dx = model->player.speed;


    /* initialize all the arrays in the game model */

    for (i = 0; i < ENTITY_COUNT; i++) {
        model->aliens[i].x = 0;
        model->aliens[i].y = 0;
        model->aliens[i].dx = 0;
        model->aliens[i].dy = 0;
        model->aliens[i].active = false;
    }
    for (i = 0; i < SHOT_COUNT; i++) {
        model->playerShots[i].x = 0;
        model->playerShots[i].y = 0;
        model->playerShots[i].active = false;
        model->playerShots[i].dx = 0;
    }
    for (i = 0; i < SHOT_COUNT; i++) {
        model->alienShots[i].x = 0;
        model->alienShots[i].y = 0;
        model->alienShots[i].active = false;
        model->alienShots[i].dx = 0;
    }
}

void updateModel(GameModel *model) {
    int i;


    movePlayer(&model->player);

    for (i = 0; i < ENTITY_COUNT; i++) {
        if (model->aliens[i].active) {
            moveAlien(&model->aliens[i]);
        }
    }

    for (i = 0; i < SHOT_COUNT; i++) {
        if (model->alienShots[i].active) {
            moveAlienShot(&model->alienShots[i]);
        }
    }

    for (i = 0; i < SHOT_COUNT; i++) {
        if (model->playerShots[i].active) {
            movePlayerShot(&model->playerShots[i]);
        }
    }

    /* updates */
    move_enemies(model);
    player_shot_out_of_screen(model);
    player_shot_collides_with_alien(model);
}

void movePlayer(Player *player){
    /* player will only move vertically */
    player->y += player->dy;
}

void moveAlien(Alien *alien) {
    alien->x += alien->dx;
    alien->y += alien->dy;
}

void moveAlienShot(AlienShot *as) {
    as->x += as->dx;
}

void movePlayerShot(PlayerShot *ps) {
    ps->x += ps->dx;
}
