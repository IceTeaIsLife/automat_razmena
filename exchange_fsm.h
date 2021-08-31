#ifndef PROJECT_2_EXCHANGE_FSM_H
#define PROJECT_2_EXCHANGE_FSM_H
#include <stdbool.h>

#if defined(__cplusplus)
extern "C" {
#endif

enum ExchangeState {
    EXCHANGE_STATE_ZERO = 0, EXCHANGE_STATE_ONE = 1, EXCHANGE_STATE_TWO = 2
};

enum ExchangeInputSymbol {
    EXCHANGE_INPUT_ONE = 1, EXCHANGE_INPUT_THREE = 3, EXCHANGE_INPUT_FIVE = 5, EXCHANGE_INPUT_TEN = 10
};

enum ExchangeOutputSymbol {
    EXCHANGE_OUTPUT_ZERO = 0, EXCHANGE_OUTPUT_ONE = 1, EXCHANGE_OUTPUT_TWO = 2, EXCHANGE_OUTPUT_THREE = 3, EXCHANGE_OUTPUT_FOUR = 4
};

struct ExchangeEngine {
    enum ExchangeState state;
};

#define DEFAULT_EXCHANGE_STATE EXCHANGE_STATE_ZERO

bool exchange_init(struct ExchangeEngine *engine);

bool exchange_reset(struct ExchangeEngine *engine);

enum ExchangeOutputSymbol exchange_engine(struct ExchangeEngine *engine, enum ExchangeInputSymbol symbol);

#if defined(__cplusplus)
}
#endif

#endif //PROJECT_2_EXCHANGE_FSM_H
