#ifndef TEMPLATEGAME_H_
#define TEMPLATEGAME_H_

#include "gameplay.h"

using namespace gameplay;

/**
 * Main game class.
 */
class RacerGame: public Game
{
public:

    /**
     * Constructror.
     */
    RacerGame();

    /**
     * @see Game::keyEvent
     */
    void keyEvent(Keyboard::KeyEvent evt, int key);

    /**
     * @see Game::touchEvent
     */
    void touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex);

    /**
     * @see Game::mouseEvent
     */
    bool mouseEvent(Mouse::MouseEvent evt, int x, int y, int wheelDelta);

    /** 
     * @see Game::gamepadEvent
     */
    void gamepadEvent(Gamepad::GamepadEvent evt, Gamepad* gamepad);

    /**
     * @see Game::menuEvent
     */
    void menuEvent();
    
protected:

    /**
     * @see Game::initialize
     */
    void initialize();

    /**
     * @see Game::finalize
     */
    void finalize();

    /**
     * @see Game::update
     */
    void update(float elapsedTime);

    /**
     * @see Game::render
     */
    void render(float elapsedTime);

private:

    /**
     * Initializes the scene.
     */
    bool initializeScene(Node* node);

    /**
     * Visits the scene to build render queues for a single frame.
     */
    bool buildRenderQueues(Node* node);

    /**
     * Draws the scene.
     */
    void drawScene();

    /**
     * Draws the splash screen.
     */
    void drawSplash(void* param);

    /**
     * Reset vehicle to its initial state.
     */
    void resetVehicle();

    Scene* _scene;
    Font* _font;
    std::vector<Node*> _renderQueues[2];
    unsigned int _keyFlags;
    unsigned int _mouseFlags;
    float _steering;
    Gamepad* _gamepad;
    Gamepad* _virtualGamepad;
    AnimationClip* _virtualGamepadClip;
    PhysicsVehicle* _carVehicle;
    Vector3 _carPositionPrevious;
    float _carSpeedLag;

    // Sounds
    AudioSource* _backgroundSound;
    AudioSource* _engineSound;
    AudioSource* _brakingSound;
};

#endif