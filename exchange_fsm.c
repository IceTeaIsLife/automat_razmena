#include "exchange_fsm.h"

enum ExchangeOutputSymbol exchange_engine(struct ExchangeEngine *engine, enum ExchangeInputSymbol symbol) {
    switch (engine->state) {
        case EXCHANGE_STATE_ZERO: {
            if (EXCHANGE_INPUT_ONE == symbol) {
                engine->state = EXCHANGE_STATE_ONE;
                return EXCHANGE_OUTPUT_ZERO;
            }
            else if (EXCHANGE_INPUT_THREE == symbol) {
                return EXCHANGE_OUTPUT_ONE;
            }
            else if (EXCHANGE_INPUT_FIVE == symbol) {
                engine->state = EXCHANGE_STATE_TWO;
                return EXCHANGE_OUTPUT_ONE;
            }
            else if (EXCHANGE_INPUT_TEN == symbol) {
                engine->state = EXCHANGE_STATE_ONE;
                return EXCHANGE_OUTPUT_THREE;
            }
            break;
        }
        case EXCHANGE_STATE_ONE: {
            if (EXCHANGE_INPUT_ONE == symbol) {
                engine->state = EXCHANGE_STATE_TWO;
                return EXCHANGE_OUTPUT_ZERO;
            }
            else if (EXCHANGE_INPUT_THREE == symbol) {
                return EXCHANGE_OUTPUT_ONE;
            }
            else if (EXCHANGE_INPUT_FIVE == symbol) {
                engine->state = EXCHANGE_STATE_ZERO;
                return EXCHANGE_OUTPUT_TWO;
            }
            else if (EXCHANGE_INPUT_TEN == symbol) {
                engine->state = EXCHANGE_STATE_TWO;
                return EXCHANGE_OUTPUT_THREE;
            }
            break;
        }
        case EXCHANGE_STATE_TWO: {
            if (EXCHANGE_INPUT_ONE == symbol) {
                engine->state = EXCHANGE_STATE_ZERO;
                return EXCHANGE_OUTPUT_ONE;
            }
            else if (EXCHANGE_INPUT_THREE == symbol) {
                return EXCHANGE_OUTPUT_ONE;
            }
            else if (EXCHANGE_INPUT_FIVE == symbol) {
                engine->state = EXCHANGE_STATE_ONE;
                return EXCHANGE_OUTPUT_TWO;
            }
            else if (EXCHANGE_INPUT_TEN == symbol) {
                engine->state = EXCHANGE_STATE_ZERO;
                return EXCHANGE_OUTPUT_FOUR;
            }
            break;
        }
    }
    return EXCHANGE_OUTPUT_ZERO;
}

bool exchange_init(struct ExchangeEngine *engine) {
    if (0 == engine)
        return false;
    engine->state = DEFAULT_EXCHANGE_STATE;
    return true;
}

bool exchange_reset(struct ExchangeEngine *engine) {
    return exchange_init(engine);
}

