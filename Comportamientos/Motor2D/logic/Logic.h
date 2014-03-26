#ifndef __LOGIC__
#define __LOGIC__

#include "IEntity.h"
#include "IEntityFactory.h"
#include "IEventManager.h"
#include "IGame.h"
#include "IIdFactory.h"
#include "IListener.h"
#include "ISceneManager.h"
#include "IScene.h"

#include "Event.h"
#include "BaseEntity.h"
#include "BaseScene.h"
#include "EntityFactory.h"
#include "Error.h"
#include "EventManager.h"
#include "Game.h"
#include "IdFactory.h"
#include "SceneManager.h"

#include "leaks.h"
#include "../json/rapidjson/document.h"

#include "IComponent.h"
#include "BaseComponent.h"
#include "IComponentFactory.h"
#include "ComponentFactory.h"

#include "EventChangeScene.h"

//ENTITIES
#include "PlayerEntity.h"
#include "BulletEntity.h"
#include "ButtonEntity.h"

//COMPONENT
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "LiveComponent.h"
#include "ShootComponent.h"
#include "MoveComponent.h"
#include "BoundCompoment.h"

//EVENTS


#endif