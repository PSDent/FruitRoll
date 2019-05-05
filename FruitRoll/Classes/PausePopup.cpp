#include "PausePopup.h"

PausePopup * PausePopup::create() {
	PausePopup *ret = new PausePopup();
	if (ret && ret->init())
	{
		ret->autorelease();
	}

	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

bool PausePopup::init() {

	MakePopUp();

	return true;
}

void PausePopup::onEnter() {

	Layer::onEnter();

	setTouchEnabled(true);

	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
}

bool PausePopup::onTouchBegan(Touch* touch, Event* event) {

	return true;
}

void PausePopup::MakePopUp() {

	auto winSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	auto fadeBack = LayerColor::create(Color4B(0, 0, 0, 0), winSize.width, winSize.height);

	this->addChild(fadeBack);

	fadeBack->runAction(FadeTo::create(0.5f, 200));

	// �˾� ��� �����
	auto pauseBg = Sprite::create("images/PopUp.png");

	pauseBg->setPosition(Point(winSize.width / 2, winSize.height / 2));

	auto BGScale = (winSize.width / pauseBg->getContentSize().width) / 2;
	pauseBg->setScale(BGScale);

	auto sprite1 = Sprite::create("images/Button.png");
	auto sprite2 = Sprite::create("images/Button.png");
	auto sprite3 = Sprite::create("images/Button.png");
	auto spriteScale = (winSize.width / sprite1->getContentSize().width) / 7;
	sprite1->setScale(spriteScale);
	sprite2->setScale(spriteScale);
	sprite3->setScale(spriteScale);
	sprite1->setPosition(Point((pauseBg->getContentSize().height / 2), (pauseBg->getContentSize().height / 2) + 100));
	sprite2->setPosition(Point((pauseBg->getContentSize().height / 2), (pauseBg->getContentSize().height / 2)));
	sprite3->setPosition(Point((pauseBg->getContentSize().height / 2), (pauseBg->getContentSize().height / 2) - 100));
	pauseBg->addChild(sprite1);
	pauseBg->addChild(sprite2);
	pauseBg->addChild(sprite3);

	this->addChild(pauseBg);

	// ���ư��� ��ư
	auto resumeMenu = MenuItemFont::create("���ư���", CC_CALLBACK_1(PausePopup::OnClickResume, this));
	resumeMenu->setColor(Color3B(255, 255, 255));
	resumeMenu->setPosition(Point((pauseBg->getContentSize().height / 2), (pauseBg->getContentSize().height / 2) + 100));
	resumeMenu->setFontNameObj("fonts/DungGeunMo.ttf");


	// �ٽý��� ��ư
	auto restartMenu = MenuItemFont::create("�ٽý���", CC_CALLBACK_1(PausePopup::OnClickRestart, this));
	restartMenu->setColor(Color3B(255, 255, 255));
	restartMenu->setPosition(Point((pauseBg->getContentSize().height / 2), (pauseBg->getContentSize().height / 2)));
	restartMenu->setFontNameObj("fonts/DungGeunMo.ttf");


	// ����ȭ�� ��ư
	auto gomainMenu = MenuItemFont::create("����ȭ��", CC_CALLBACK_1(PausePopup::OnClickGoMain, this));
	gomainMenu->setColor(Color3B(255, 255, 255));
	gomainMenu->setPosition(Point((pauseBg->getContentSize().height / 2), (pauseBg->getContentSize().height / 2) - 100));
	gomainMenu->setFontNameObj("fonts/DungGeunMo.ttf");

	// �޴� ����
	auto menu = Menu::create(resumeMenu, restartMenu, gomainMenu, NULL);
	menu->setPosition(Point::ZERO);

	pauseBg->addChild(menu, 1);
}

void PausePopup::OnClickResume(Ref* object) {
	((GameScene *)this->getParent())->Resume();
	this->removeFromParentAndCleanup(true);
}

void PausePopup::OnClickRestart(Ref* object) {
	((GameScene *)this->getParent())->Resume();
	((GameScene *)this->getParent())->Restart();
	this->removeFromParentAndCleanup(true);
}

void PausePopup::OnClickGoMain(Ref* object) {
	((GameScene *)this->getParent())->GoMain();
}