#include "Player.h"

Player::Player(float x, float y, sf::Texture& texture_sheet):
    textureSheet(texture_sheet), animationCut(0)
{
    this->setPosition(x, y);

    this->initVariables();
    this->initComponents();
    this->initAnimations();
}

Player::~Player()
{
    //dtor
}

void Player::initVariables(){

}

void Player::initComponents(){
    this->createHitboxComponent(this->sprite, 5.f, 5.f, 46, 55);
    this->createMovementComponent(500.f, 20.f, 10.f);
    this->createAnimationComponent(this->textureSheet);
}

void Player::initAnimations(){
    this->animationComponent->addAnimation("IDLE",20.f,0,0, 8,0,64,64);
    this->animationComponent->addAnimation("WALK",2.5,0,1, 5,1,64,64);
    this->animationComponent->addAnimation("SPRINT",2.5,0,2,4,2,64,64);
    this->animationComponent->addAnimation("CUT",10.f,6,1,9,1,64,64);
    this->animationComponent->addAnimation("BACKWALK",2.5,5,2,9,2,64,64);
}

void Player::update(const float&dt){
    this->movementComponent->update(dt);

    this->updateAnimation(dt);

    this->hitboxComponent->update();
}

void Player::updateAnimation(const float & dt)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition();

    bool left = this->sprite.getPosition().x + sprite.getGlobalBounds().width/2 < mousePos.x;
    bool backwalk = false;
    if(left){//LEFT
        this->sprite.setOrigin(0.f,0.f);
        this->sprite.setScale(1.f,1.f);
        if(this->movementComponent->getMovingState(SPRINT_LEFT)) {this->movementComponent->setMaxVelocity(250); backwalk = true;}
        else if(this->movementComponent->getMovingState(MOVING_LEFT)) {this->movementComponent->setMaxVelocity(250);backwalk = true;}
        else {this->movementComponent->setMaxVelocity(500);backwalk = false;}
    }
    else{//RIGHT
        this->sprite.setOrigin(55.f,0.f);
        this->sprite.setScale(-1.f,1.f);
        if(this->movementComponent->getMovingState(SPRINT_RIGHT)) {this->movementComponent->setMaxVelocity(250);backwalk = true;}
        else if(this->movementComponent->getMovingState(MOVING_RIGHT)) {this->movementComponent->setMaxVelocity(250);backwalk = true;}
        else {this->movementComponent->setMaxVelocity(500);backwalk = false;}
    }



    if(animationCut){
        this->animationComponent->play("CUT", dt,true);
        if(this->animationComponent->isDone("CUT")){
            animationCut = false;
        }
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !animationCut){
        animationCut = true;
        this->animationComponent->play("CUT", dt,true);
    }
    else if(this->movementComponent->getMovingState(IDLE)){
        this->animationComponent->play("IDLE", dt);
    } else if(backwalk) {
        this->animationComponent->play("BACKWALK", dt);
    } else if(this->movementComponent->getMovingState(SPRINT)){
        this->animationComponent->play("SPRINT", dt);
    } else if(this->movementComponent->getMovingState(MOVING)){
        this->animationComponent->play("WALK", dt);
    }
}

void Player::interact(Entity& sender){
    sf::FloatRect mouseRect(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y, 1, 1);
    if(this->hitboxComponent->checkIntersect(mouseRect)){
        std::cout << "player interact with player" << std::endl;
        std::cout << "sender: " << sender.getInfo() << std::endl;
    }
}

std::string Player::getInfo(){
    return "Player";
}
