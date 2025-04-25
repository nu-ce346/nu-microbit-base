// Snake Game "driver"
// Runs the snake game on top of the LED matrix

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrfx_gpiote.h"

#include "microbit_v2.h"
#include "led_matrix.h"

// represent snake body part locations
typedef struct {
  int8_t row;
  int8_t col;
} snakeloc_t;

// represent movement direction of the snake
typedef enum {
  UP = 1,
  LEFT,
  DOWN,
  RIGHT,
} snakedir_t;

// collecting the many variables we need to track the game's state
//  In C++ we'd just make a class, but alas we're in C...
typedef struct {
  // model of the current game state
  //  True means a snake body piece is in that location
  //  False means nothing is in that location
  bool model[5][5];

  // current position of the head of the snake
  snakeloc_t head;

  // current direction the snake is traveling in
  snakedir_t dir;

  // button pressed since last iteration
  //  0 means no button has been pressed
  //  Otherwise set to BTN_A or BTN_B
  uint8_t button_pressed;

  // iterations since the game has started (for high score)
  // also used to determine when to grow the snake
  uint8_t iterations;

  // whether the game is still running or not
  bool game_over;
} game_state_t;

static game_state_t game_state;


// ***** Queue implementation *****
// Implemented using a ring buffer
// You shouldn't have to edit this

// A queue that holds snakeloc_t structs
// 25 slots is enough for a maximum-sized snake given our screen dimensions
typedef struct {
  snakeloc_t slots[25];
  uint8_t head;
  uint8_t tail;
} queue_t;

static queue_t queue;

// Initializes the queue
static void queue_init(void) {
  for (int i=0; i<25; i++) {
    queue.slots[i].row = -1;
    queue.slots[i].col = -1;
  }
  queue.head = 0;
  queue.tail = 0;
}

// Pushes an item to the head of the queue
// Overwrites the tail of the queue if the queue is full
static void queue_push_head(snakeloc_t position) {
  // head points at empty slot, write there
  queue.slots[queue.head] = position;

  // advance head
  queue.head++;
  if (queue.head >= 25) {
    queue.head = 0;
  }
}

// Pops an item from the tail of the queue
// Returns {-1, -1} if no item exists
static snakeloc_t queue_pop_tail(void) {
  // tail points at last element unless head and tail overlap, read there
  snakeloc_t result = {-1, -1};
  if (queue.tail != queue.head) {
    result.row = queue.slots[queue.tail].row;
    result.col = queue.slots[queue.tail].col;
  }

  // advance tail
  queue.tail++;
  if (queue.tail >= 25) {
    queue.tail = 0;
  }

  return result;
}

// ********************************


// button press callback function
// you should not need to edit this, but you can if you want to
static void gpio_handler(nrfx_gpiote_pin_t pin, nrf_gpiote_polarity_t _unused) {
  // overwrite the current button pressed as this one
  // if multiple buttons have been pressed, only the most recent is saved
  game_state.button_pressed = (uint8_t)pin;
}

// intialize the game state
// you should not need to edit this, but you can if you want to
void snake_game_init(void) {
  // initialize game state
  memset(game_state.model, false, 5*5*sizeof(bool));
  game_state.head.row = 2;
  game_state.head.col = 0;
  game_state.dir = RIGHT;
  game_state.button_pressed = 0;
  game_state.iterations = 0;
  game_state.game_over = false;

  // initial snake position
  game_state.model[game_state.head.row][game_state.head.col] = true;

  // initialize ring buffer
  // push initial head into the queue
  queue_init();
  queue_push_head(game_state.head);

  // initialize button inputs
  // calls the `gpio_handler` callback function when either button is pressed
  nrfx_gpiote_init();
  nrfx_gpiote_in_config_t in_config = NRFX_GPIOTE_CONFIG_IN_SENSE_LOTOHI(true); // high-accuracy mode
  nrfx_gpiote_in_init(BTN_A, &in_config, gpio_handler);
  nrfx_gpiote_in_event_enable(BTN_A, true); // enable interrupts for BTN_A
  nrfx_gpiote_in_init(BTN_B, &in_config, gpio_handler);
  nrfx_gpiote_in_event_enable(BTN_B, true); // enable interrupts for BTN_B
}

// advance the game state
// this is intended to be called repeatedly from the main code, with a delay between each call
// each call advances the game state one iteration
void snake_game_advance_state(void) {
  // if the game is over, no longer advance the state
  // TODO

  // handle button presses
  //  If BTN_A was pressed, rotate left from the current direction
  //  If BTN_B was pressed, rotate right from the current direction
  //    e.g., if previously going right, now go down instead
  // TODO

  // remove the snake tail from the queue and the model
  //  unless the number of iterations is a multiple of ten,
  //  in which case grow the snake by simply NOT removing the tail
  // TODO

  // advance the snake head location based on the current direction
  // TODO

  // check for collision with game boarders (<0 or >4) or with the snake itself
  //  if the new head position was already true in the model, that's a collision
  //
  // In the case of a collision:
  //  game_over should become true
  //  print a message with the number of iterations (the current score)
  //  draw or write something notable on the LED matrix so it's clear the game ended
  // TODO

  // update game state with new head location in the model and the queue
  // TODO

  // display the game model on the LED matrix
  // TODO
}


