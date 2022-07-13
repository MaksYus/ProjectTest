#include "Player.h"

Player::Player(float x, float y, std::map<std::string, sf::Texture>  texture_sheets):
    textureSheets(texture_sheets), animationCut(0)
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
    this->createAnimationComponent();
}

void Player::initAnimations(){

//walk
    this->animationComponent->addAnimation(this->textureSheets["PLAYER_DWARF_ARMOR_WALK"],"WALK ARMOR",100.f,0,0, 0,0,64,64);
    this->animationComponent->addAnimation(this->textureSheets["PLAYER_DWARF_WEAPON_WALK"],"WALK AXE",7.5,0,0, 1,0,64,64);
    this->animationComponent->addAnimation(this->textureSheets["PLAYER_DWARF_HEAD_WALK"],"WALK HEAD",7.5,0,0, 1,0,64,64);
    this->animationComponent->addAnimation(this->textureSheets["PLAYER_DWARF_LEGS_WALK"],"WALK LEGS",2.5,0,0, 5,0,64,64);

    this->animationComponent->addAnimation(this->textureSheets["PLAYER_SHEET"],"IDLE",20.f,0,0, 8,0,64,64);
    this->animationComponent->addAnimation(this->textureSheets["PLAYER_SHEET"],"WALK",3.5,0,1, 5,1,64,64);
    this->animationComponent->addAnimation(this->textureSheets["PLAYER_SHEET"],"SPRINT",2.5,0,2,4,2,64,64);
    this->animationComponent->addAnimation(this->textureSheets["PLAYER_SHEET"],"CUT",10.f,6,1,9,1,64,64);
    this->animationComponent->addAnimation(this->textureSheets["PLAYER_SHEET"],"BACKWALK",2.5,5,2,9,2,64,64);

    this->cutAnim.push_back("CUT");

    this->idleAnim.push_back("IDLE");

    this->bacwalkAnim.push_back("BACKWALK");

    this->sprintAnim.push_back("SPRINT");
    this->walkAnim.push_back("WALK");

    //this->walkAnim.push_back("WALK ARMOR");
    //this->walkAnim.push_back("WALK LEGS");
    //this->walkAnim.push_back("WALK AXE");
    //this->walkAnim.push_back("WALK HEAD");
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
        this->animationComponent->play(this->cutAnim, dt,true);
        if(this->animationComponent->isDone("CUT")){
            animationCut = false;
        }
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !animationCut){
        animationCut = true;
        this->animationComponent->play(this->cutAnim, dt,true);
    }
    else if(this->movementComponent->getMovingState(IDLE)){
        this->animationComponent->play(this->idleAnim, dt);
    } else if(backwalk) {
        this->animationComponent->play(this->bacwalkAnim, dt);
    } else if(this->movementComponent->getMovingState(SPRINT)){
        this->animationComponent->play(this->sprintAnim, dt);
    } else if(this->movementComponent->getMovingState(MOVING)){
        this->animationComponent->play(this->walkAnim, dt);
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
