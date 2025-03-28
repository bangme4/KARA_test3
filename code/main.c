<<<<<<< HEAD

=======
>>>>>>> refs/remotes/origin/main
#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

<<<<<<< HEAD

// Window
#define WINDOW_TITLE "KARA"
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800

//Image type
#define IMAGE_FLAGS (IMG_INIT_JPG | IMG_INIT_PNG)

//Map dimention and tile size
=======
#define WINDOW_TITLE "KARA"
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define IMAGE_FLAGS (IMG_INIT_JPG | IMG_INIT_PNG)
>>>>>>> refs/remotes/origin/main
#define MAP_WIDTH 100
#define MAP_HEIGHT 100
#define TILE_SIZE 24
#define PLAYER_FRAME_COUNT 4
Mix_Music *button_click_music;

<<<<<<< HEAD
// Structure to store game-related elements
=======

>>>>>>> refs/remotes/origin/main
struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *background;
    SDL_Texture *logo;
    SDL_Texture *background_start;
    SDL_Texture *background_settings;
    SDL_Texture *playerTexture;
    SDL_Texture *settings;
    SDL_Texture *story;
    SDL_Texture *story2;
    SDL_Texture *story3;
    SDL_Texture *story4;
    Mix_Music *menu_music;
    Mix_Chunk *button_hover_sound;
    // MIX_Music *game_music;
    // Mix_Music *settings_music;
    int map[MAP_HEIGHT][MAP_WIDTH];
};
<<<<<<< HEAD
// Structure to store player-related elements
=======

>>>>>>> refs/remotes/origin/main
struct Player {
    int x, y; 
    int speed;
    bool isAttacking;
    int attackCooldown;
};
<<<<<<< HEAD
// Structure to store camera-related elements
=======

>>>>>>> refs/remotes/origin/main
struct Camera {
    int x, y;
    float scale;
};
<<<<<<< HEAD
// Structure to store button-related elements
=======

>>>>>>> refs/remotes/origin/main
struct Button {
    SDL_Rect rect;
    SDL_Texture *texture;
    SDL_Texture *hover_texture;
    SDL_Texture *original_texture;
    SDL_Rect originalRect;
    bool hover_played;
};
<<<<<<< HEAD
// Functions for player render
=======

>>>>>>> refs/remotes/origin/main
void render_player(SDL_Renderer *renderer, struct Player *player, struct Camera *camera) {
    SDL_Rect playerRect = { 
        (player->x - camera->x) * camera->scale, 
        (player->y - camera->y) * camera->scale, 
        24 * camera->scale,
        24 * camera->scale 
    };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
    SDL_RenderFillRect(renderer, &playerRect);
}
<<<<<<< HEAD
// Functions for map render
=======

>>>>>>> refs/remotes/origin/main
void render_map(SDL_Renderer *renderer, struct Camera *camera) {
    int tile_size = 24;
    int map_size = 100;

    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

<<<<<<< HEAD
    // Render map
=======
>>>>>>> refs/remotes/origin/main
    for (int y = 0; y < map_size; y++) {
        for (int x = 0; x < map_size; x++) {
            SDL_Rect tileRect = {
                (x * tile_size - camera->x) * camera->scale,  
                (y * tile_size - camera->y) * camera->scale,  
                tile_size * camera->scale,                    
                tile_size * camera->scale                  
            };

            SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
            SDL_RenderFillRect(renderer, &tileRect);

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawRect(renderer, &tileRect);
        }
    }
}
<<<<<<< HEAD
// Functions for player input
void handle_input(SDL_Event *event, struct Player *player, struct Camera *camera) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    // Player movement
=======

void handle_input(SDL_Event *event, struct Player *player, struct Camera *camera) {
    const Uint8 *state = SDL_GetKeyboardState(NULL);

>>>>>>> refs/remotes/origin/main
    if (state[SDL_SCANCODE_W]) player->y -= player->speed;
    if (state[SDL_SCANCODE_S]) player->y += player->speed;
    if (state[SDL_SCANCODE_A]) player->x -= player->speed;
    if (state[SDL_SCANCODE_D]) player->x += player->speed;

<<<<<<< HEAD

    // Player attack
=======
>>>>>>> refs/remotes/origin/main
    if (state[SDL_SCANCODE_SPACE] && player->attackCooldown == 0) {
        player->isAttacking = true;
        player->attackCooldown = 20;

        Mix_Chunk *attack_sound = Mix_LoadWAV("../assets/sounds/attack.wav");
        if (player->isAttacking) {
            Mix_PlayChannel(-1, attack_sound, 0);
        }
    }

<<<<<<< HEAD
    // Player attack cooldown
=======
>>>>>>> refs/remotes/origin/main
    if (player->attackCooldown > 0) {
        player->attackCooldown--;
    }

<<<<<<< HEAD

    // Camera zoom
=======
>>>>>>> refs/remotes/origin/main
    if (player->x < 0) player->x = 0;
    if (player->x > MAP_WIDTH * TILE_SIZE - 24) player->x = MAP_WIDTH * TILE_SIZE - 24;
    if (player->y < 0) player->y = 0;
    if (player->y > MAP_HEIGHT * TILE_SIZE - 24) player->y = MAP_HEIGHT * TILE_SIZE - 24;

<<<<<<< HEAD
    camera->x = player->x - SCREEN_WIDTH / (2 * camera->scale);
    camera->y = player->y - SCREEN_HEIGHT / (2 * camera->scale);
}
// Functions for player attack render
=======

    camera->x = player->x - SCREEN_WIDTH / (2 * camera->scale);
    camera->y = player->y - SCREEN_HEIGHT / (2 * camera->scale);
}

>>>>>>> refs/remotes/origin/main
void render_attack(SDL_Renderer *renderer, struct Player *player, struct Camera *camera) {
    if (!player->isAttacking) return;

    SDL_Rect attackRect = {
        (player->x - camera->x + 20) * camera->scale,
        (player->y - camera->y) * camera->scale,
        30 * camera->scale,
        10 * camera->scale
    };

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // Yellow attack
    SDL_RenderFillRect(renderer, &attackRect);

    player->isAttacking = false;
}


<<<<<<< HEAD
// Functions for button render
void button_render(SDL_Renderer *renderer, struct Button *button) {
    SDL_RenderCopy(renderer, button->texture, NULL, &button->rect);
}
// Functions for button hover
=======

void button_render(SDL_Renderer *renderer, struct Button *button) {
    SDL_RenderCopy(renderer, button->texture, NULL, &button->rect);
}

>>>>>>> refs/remotes/origin/main
void handle_button_hover(struct Button *button, int mouseX, int mouseY, struct Game *game) {
    if (mouseX >= button->rect.x && mouseX <= button->rect.x + button->rect.w &&
        mouseY >= button->rect.y && mouseY <= button->rect.y + button->rect.h) {
        
<<<<<<< HEAD
            // Play hover sound
=======
>>>>>>> refs/remotes/origin/main
        if (!button->hover_played) {
            Mix_PlayChannel(-1, game->button_hover_sound, 0);
            button->hover_played = true;
        }
<<<<<<< HEAD
        // Increase button size
=======
        
>>>>>>> refs/remotes/origin/main
        button->rect.w = button->originalRect.w * 1.1;
        button->rect.h = button->originalRect.h * 1.1;
        button->rect.x = button->originalRect.x - (button->rect.w - button->originalRect.w) / 2;
        button->rect.y = button->originalRect.y - (button->rect.h - button->originalRect.h) / 2;

        button->texture = button->hover_texture;
<<<<<<< HEAD
    }
    // Reset button size
    else {
=======

    } else {
>>>>>>> refs/remotes/origin/main
        if (button->hover_played) {
            button->hover_played = false;
        }
        button->rect = button->originalRect;
        button->texture = button->original_texture;
    }
}
<<<<<<< HEAD
// Functions for game end
=======

>>>>>>> refs/remotes/origin/main
void game_cleanup(struct Game *game, int exit_status) {
    SDL_DestroyTexture(game->background);
    SDL_DestroyTexture(game->logo);
    SDL_DestroyTexture(game->story);
    SDL_DestroyTexture(game->story2);
    SDL_DestroyTexture(game->story3);
    SDL_DestroyTexture(game->story4);
    SDL_DestroyTexture(game->settings);
    if (game->renderer) {
        SDL_DestroyRenderer(game->renderer);
    }
    if (game->window) {
        SDL_DestroyWindow(game->window);
    }
    Mix_FreeMusic(game->menu_music);
    Mix_FreeMusic(button_click_music);
    Mix_FreeChunk(game->button_hover_sound);
    Mix_CloseAudio();
    IMG_Quit();
    SDL_Quit();
    exit(exit_status);
}

<<<<<<< HEAD
// Function prototypes
=======
>>>>>>> refs/remotes/origin/main
bool sdl_initiate(struct Game *game);
bool load_media(struct Game *game);
bool button_init(struct Button *button, SDL_Renderer *renderer, const char *image_path, const char *hover_image_path, int x, int y, int w, int h);
bool button_is_clicked(struct Button *button, SDL_Event *event);
void handle_button_hover(struct Button *button, int mouseX, int mouseY, struct Game *game);
<<<<<<< HEAD
 // Main function
=======
 
>>>>>>> refs/remotes/origin/main
int main(){
    struct Game game ={
        .window = NULL,
        .renderer = NULL,
        .background = NULL,
        .logo = NULL,
        .settings = NULL,
        .story = NULL,
        .story2 = NULL,
        .story3 = NULL,
        .story4 = NULL,
    };

<<<<<<< HEAD
    // Initialize game elements
=======
>>>>>>> refs/remotes/origin/main
    struct Button button1, button2, button3, sbutton;
    struct Player player = { 500, 500, 3 };
    struct Camera camera = { 0, 0, 2.0f };

<<<<<<< HEAD
    // Start page
    int page = 0;

    // Initialize SDL
=======
    int page = 0;

>>>>>>> refs/remotes/origin/main
    if(sdl_initiate(&game)) {
        game_cleanup(&game, EXIT_FAILURE);
    }

<<<<<<< HEAD
    // Load media
=======
>>>>>>> refs/remotes/origin/main
    if(load_media(&game)) {
        game_cleanup(&game, EXIT_FAILURE);
    }

<<<<<<< HEAD
    // Play menu music
    Mix_PlayMusic(game.menu_music, -1);

    // Initialize buttons
=======
    Mix_PlayMusic(game.menu_music, -1);


>>>>>>> refs/remotes/origin/main
    if (button_init(&button1, game.renderer, "../assets/button1.png", "../assets/button1p.png", 475, 600, 250, 80) ||
    button_init(&button2, game.renderer, "../assets/button2.png", "../assets/button2p.png", 475, 500, 250, 80) ||
    button_init(&button3, game.renderer, "../assets/button3.png", "../assets/button3p.png", 475, 400, 250, 80) ||
    button_init(&sbutton, game.renderer, "../assets/sbutton.png", "../assets/sbuttonp.png", 960, 700, 200, 60) ) {
    game_cleanup(&game, EXIT_FAILURE);
}


    while (true) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    game_cleanup(&game, EXIT_SUCCESS);
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_ESCAPE:
                            // game_cleanup(&game, EXIT_SUCCESS);
                            game.background = game.background;
                            page = 0;
                            Mix_HaltMusic();
                            Mix_PlayMusic(game.menu_music, -1);
                            break;
                        default:
                            break;
                    }
                    break;
<<<<<<< HEAD
                // Handle mouse hover and click
=======
        
>>>>>>> refs/remotes/origin/main
                case SDL_MOUSEMOTION:
                    if (page == 0) {
                        handle_button_hover(&button1, event.motion.x, event.motion.y, &game);
                        handle_button_hover(&button2, event.motion.x, event.motion.y, &game);
                        handle_button_hover(&button3, event.motion.x, event.motion.y, &game);
                    }
                    else if (page == 4) {
                        handle_button_hover(&sbutton, event.motion.x, event.motion.y, &game);
                    }
                    else if (page == 5) {
                        handle_button_hover(&sbutton, event.motion.x, event.motion.y, &game);
                    }
                    else if (page == 6) {
                        handle_button_hover(&sbutton, event.motion.x, event.motion.y, &game);
                    }
                    else if (page == 7) {
                        handle_button_hover(&sbutton, event.motion.x, event.motion.y, &game);
                    }
                    break;
<<<<<<< HEAD
                // Handle mouse click
=======
        
>>>>>>> refs/remotes/origin/main
                case SDL_MOUSEBUTTONDOWN:
                    if (button_is_clicked(&button1, &event)) {
                        Mix_HaltMusic();
                        Mix_PlayMusic(button_click_music, 1);
                        page = 1;
                    }
                    if (button_is_clicked(&button2, &event)) {
                        Mix_HaltMusic();
                        Mix_PlayMusic(button_click_music, 1);
                        // Mix_PlayMusic(game.settings_music, -1);
                        page = 2;
                    }
                    if (button_is_clicked(&button3, &event)) {
                        Mix_HaltMusic();
                        Mix_PlayMusic(button_click_music, 1);
                        // Mix_PlayMusic(game.game_music, -1);
                        page = 4;
                    }
                    if (button_is_clicked(&sbutton, &event)) {
                        Mix_HaltMusic();
                        Mix_PlayMusic(button_click_music, 1);
                        if(page == 4) {
                            page = 5;
                        } else if(page == 5) {
                            page = 6;
                        } else if(page == 6) {
                            page = 7;
                        } else if(page == 7) {
                            page = 3;
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        handle_input(&event, &player, &camera);
        
        SDL_RenderClear(game.renderer);

        SDL_RenderCopy(game.renderer, game.background, NULL, NULL);

<<<<<<< HEAD
        // Pages and what they do
=======
        
>>>>>>> refs/remotes/origin/main
        if (page == 0) {
            SDL_Rect logoRect = {375, 150, 450, 170};
            SDL_RenderCopy(game.renderer, game.logo, NULL, &logoRect);

            button_render(game.renderer, &button1);
            button_render(game.renderer, &button2);
            button_render(game.renderer, &button3);
        } 
        else if (page == 1) {
            game_cleanup(&game, EXIT_SUCCESS);
        }
        else if (page == 2) {
            // game.background = game.background_settings;
            SDL_Rect settingsRect = {200, 100, 800, 600};
            SDL_RenderCopy(game.renderer, game.settings, NULL, &settingsRect);
        }
        else if (page == 3) {
            // game.background = game.background_start;
            render_map(game.renderer, &camera);
            render_player(game.renderer, &player, &camera);
            render_attack(game.renderer, &player, &camera);
        }
        else if (page == 4) {
            SDL_Rect storyRect = {100, 100, 1000, 560};
            SDL_RenderCopy(game.renderer, game.story, NULL, &storyRect);
            button_render(game.renderer, &sbutton);
            // story page 1
        }
        else if (page == 5) {
            SDL_Rect storyRect = {100, 100, 1000, 560};
            SDL_RenderCopy(game.renderer, game.story2, NULL, &storyRect);
            button_render(game.renderer, &sbutton);
            // dtory page 2
        }
        else if (page == 6) {
            SDL_Rect storyRect = {100, 100, 1000, 560};
            SDL_RenderCopy(game.renderer, game.story3, NULL, &storyRect);
            button_render(game.renderer, &sbutton);
            // story page 3
        }
        else if (page == 7) {
            SDL_Rect storyRect = {100, 100, 1000, 560};
            SDL_RenderCopy(game.renderer, game.story4, NULL, &storyRect);
            button_render(game.renderer, &sbutton);
            // story page 4
        }
        
        SDL_RenderPresent(game.renderer);

        SDL_Delay(16);
    }

    SDL_DestroyTexture(button1.texture);
    SDL_DestroyTexture(button2.texture);
    SDL_DestroyTexture(button3.texture);
    SDL_DestroyTexture(sbutton.texture);
    game_cleanup(&game, EXIT_SUCCESS);
    
    return 0;
}
<<<<<<< HEAD
// Function definitions
=======

>>>>>>> refs/remotes/origin/main
bool sdl_initiate(struct Game *game) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error SDL: %s\n", SDL_GetError());
        return true;
    }

    int img_init = IMG_Init(IMAGE_FLAGS);
    if((img_init & IMAGE_FLAGS) !=IMAGE_FLAGS){
        fprintf(stderr, "Error IMG: %s\n", IMG_GetError());
        return true;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        fprintf(stderr, "Error SDL_mixer: %s\n", Mix_GetError());
        return true;
    }


    game->window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (game->window == NULL) {
        fprintf(stderr, "Error Window: %s\n", SDL_GetError());
        return true;
    }

    game->renderer = SDL_CreateRenderer(game->window, -1, 0);
    if (game->renderer == NULL) {
        fprintf(stderr, "Error Renderer: %s\n", SDL_GetError());
        return true;
    }
    
    SDL_SetRenderDrawBlendMode(game->renderer, SDL_BLENDMODE_BLEND);

    return false;
}
<<<<<<< HEAD
// Function to load media
=======

>>>>>>> refs/remotes/origin/main
bool load_media(struct Game *game) {
    game->background = IMG_LoadTexture(game->renderer, "../assets/background.jpg");
    // game->background_start = IMG_LoadTexture(game->renderer, "../assets/background_start.jpg");
    game->background_settings = IMG_LoadTexture(game->renderer, "../assets/background_settings.jpg");
    if (game->background == NULL) {
        fprintf(stderr, "Error Background: %s\n", SDL_GetError());
        return true;
    }

    game->logo = IMG_LoadTexture(game->renderer, "../assets/logo.png");
    if (game->logo == NULL) {
        fprintf(stderr, "Error Logo: %s\n", SDL_GetError());
        return true;
    }
    game->story = IMG_LoadTexture(game->renderer, "../assets/story.png");
    if (game->story == NULL) {
        fprintf(stderr, "Error Story: %s\n", SDL_GetError());
        return true;
    }
    game->story2 = IMG_LoadTexture(game->renderer, "../assets/story2.png");
    if (game->story2 == NULL) {
        fprintf(stderr, "Error Story2: %s\n", SDL_GetError());
        return true;
    }
    game->story3 = IMG_LoadTexture(game->renderer, "../assets/story3.png");
    if (game->story3 == NULL) {
        fprintf(stderr, "Error Story3: %s\n", SDL_GetError());
        return true;
    }
    game->story4 = IMG_LoadTexture(game->renderer, "../assets/story4.png");
    if (game->story4 == NULL) {
        fprintf(stderr, "Error Story4: %s\n", SDL_GetError());
        return true;
    }

    game->settings = IMG_LoadTexture(game->renderer, "../assets/settings.png");
    if (game->settings == NULL) {
        fprintf(stderr, "Error Settings: %s\n", SDL_GetError());
        return true;
    }

    game->menu_music = Mix_LoadMUS("../assets/music/menu_music.mp3");
    // game->settings_music = Mix_LoadMUS("../assets/settings_music.mp3");
    // game->game_music = Mix_LoadMUS("../assets/game_music.mp3");

    // if (!game->menu_music || !game->settings_music || !game->game_music) {
    if (!game->menu_music) {
        fprintf(stderr, "Error Loading Music: %s\n", Mix_GetError());
        return true;
    }

    button_click_music = Mix_LoadMUS("../assets/sounds/click.mp3");
    if (!button_click_music) {
        fprintf(stderr, "Error Loading Click Music: %s\n", Mix_GetError());
        return true;
    }

    game->button_hover_sound = Mix_LoadWAV("../assets/sounds/hover_sound.wav");
    if (!game->button_hover_sound) {
        fprintf(stderr, "Error Loading Hover Sound: %s\n", Mix_GetError());
        return true;
    }


    return false;
}
<<<<<<< HEAD
// Function to initialize button
=======

>>>>>>> refs/remotes/origin/main
bool button_init(struct Button *button, SDL_Renderer *renderer, const char *image_path, const char *hover_image_path, int x, int y, int w, int h) {
    button->texture = IMG_LoadTexture(renderer, image_path);
    button->hover_texture = IMG_LoadTexture(renderer, hover_image_path);
    button->original_texture = button->texture;

    if (!button->texture || !button->hover_texture) {
        fprintf(stderr, "Error Button Texture: %s\n", SDL_GetError());
        return true;
    }

    button->rect = (SDL_Rect){x, y, w, h};
    button->originalRect = button->rect;
    button->hover_played = false;
    return false;
}

<<<<<<< HEAD
// Function to check if button is clicked
=======

>>>>>>> refs/remotes/origin/main
bool button_is_clicked(struct Button *button, SDL_Event *event) {
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        int mouseX = event->button.x;
        int mouseY = event->button.y;
        if (mouseX >= button->rect.x && mouseX <= button->rect.x + button->rect.w &&
            mouseY >= button->rect.y && mouseY <= button->rect.y + button->rect.h) {
            return true;
        }
    }
    return false;
}