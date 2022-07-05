#include "Entity.h"

Entity::Entity()
{
    this->initVariables();
}

Entity::~Entity()
{
    delete this->hitboxComponent;
    delete this->movementComponent;
    delete this->animationComponent;
}

void Entity::update(const float& dt){
    if(this->movementComponent){
        this->movementComponent->update(dt);
    }
}

void Entity::render(sf::RenderTarget& target){
    target.draw(this->sprite);

    if(this->hitboxComponent)
        this->hitboxComponent->render(target);
}

void Entity::initVariables(){
    this->hitboxComponent = NULL;
    this->movementComponent = NULL;
    this->animationComponent = NULL;
}

void Entity::setTexture(sf::Texture& texture){
    this->sprite.setTexture(texture);
}

void Entity::createHitboxComponent( sf::Sprite& Sprite, float x, float y, float width, float height){
    this->hitboxComponent = new HitboxComponent(sprite, x, y, width, height);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float decceleration){
    this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, decceleration);
}

void Entity::createAnimationComponent( sf::Texture& texture_sheet){
    this->animationComponent = new AnimationComponent(this->sprite,texture_sheet);
}

void Entity::setPosition(const float x, const float y){
           this->sprite.setPosition(x, y);
}

void Entity::move(const float dir_x, const float dir_y, const float& dt){
    if(this->movementComponent){
            this->movementComponent->move(dir_x,dir_y, dt);
    }
}

void Entity::interact(Entity& sender){
    std::cout << sender.getInfo() << " interact with " << this->getInfo() << std::endl;
}

std::string Entity::getInfo(){
    return "Entity";
}
//руководство пользователя еас сгм криста, звонила милехина, попросила уточнить



