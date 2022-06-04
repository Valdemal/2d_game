#include <memory>
#include "../Map/Map.h"
#include "../Modifier/HealthBooster.h"
#include "../Enemy/Clone.h"


typedef std::shared_ptr<Entity> entityPtr;

class EntityFactory {
public:
    static entityPtr create(mapObject object, float x = 0, float y = 0) {
        switch (object) {
            case mapObject::HealthBooster:
                return entityPtr(new HealthBooster(x, y));
            case mapObject::Clone:
                return entityPtr(new Clone(x, y));
            default:
                throw std::runtime_error("Invalid type of argument!");
        }
    }
};
