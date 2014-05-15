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
#include "ISoundFactory.h"
#include "ISample.h"

//UTILS
#include "leaks.h"
#include "../json/rapidjson/document.h"
#include "../bass/bass.h"

//FACTORIES
#include "EntityFactory.h"
#include "ComponentFactory.h"
#include "IdFactory.h"
#include "SoundFactory.h"
#include "ScreenManager.h"

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
#include "ButtonEntity.h"
#include "BSOEntity.h"
#include "StaticObstacleEntity.h"
#include "BulletEntity.h"
#include "FinishSceneEntity.h"
#include "DynamicObstacleEntity.h"

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
#include "WaveMovementComponent.h"
#include "TeamComponent.h"
#include "LabelComponent.h"
#include "BoundEliminatorComponent.h"

//SCENES
#include "BaseScene.h"

//SAMPLES
#include "BaseSample.h"
#include "StreamSample.h"
#include "LoadedSample.h"

//EVENTS
#include "Event.h"
#include "EventChangeScene.h"

#endif