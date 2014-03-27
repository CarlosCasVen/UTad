#ifndef __LOGIC__
#define __LOGIC__

#define LEAK_CONTROL

#include "Event.h"
#include "Error.h"

//INTERFACES
#include "IEntity.h"
#include "IEntityFactory.h"
#include "IEventManager.h"
#include "IGame.h"
#include "IIdFactory.h"
#include "IListener.h"
#include "ISceneManager.h"
#include "IScene.h"
#include "ICollisionListener.h"
#include "ICollisionManager.h"
#include "IScreenManager.h"
#include "ISoundManager.h"
#include "IComponentFactory.h"
#include "IComponent.h"

//UTILS
#include "leaks.h"
#include "../json/rapidjson/document.h"
#include "../bass/bass.h"

//FACTORIES
#include "EntityFactory.h"
#include "ComponentFactory.h"
#include "IdFactory.h"

//MANAGERS
#include "Game.h"
#include "SceneManager.h"
#include "ScreenManager.h"
#include "SoundManager.h"
#include "EventManager.h"
#include "CollisionManagerL.h"

//ENTITIES
#include "BaseEntity.h"
#include "PlayerEntity.h"
#include "BulletEntity.h"
#include "ButtonEntity.h"

//COMPONENT
#include "BaseComponent.h"
#include "SpriteComponent.h"
#include "InputComponent.h"
#include "LiveComponent.h"
#include "MoveComponent.h"
#include "BoundCompoment.h"
#include "CollisionComponent.h"
#include "DamageComponent.h"
#include "AnimatorComponent.h"

//SCENES
#include "BaseScene.h"

#endif