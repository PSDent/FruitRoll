#include "GameoverPopup.h"

GameoverPopup * GameoverPopup::create() {
	GameoverPopup *ret = new GameoverPopup();
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

bool GameoverPopup::init() {

	MakePopUp();

	return true;
}

void GameoverPopup::onEnter() {

	Layer::onEnter();

	setTouchEnabled(true);

	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
}

bool GameoverPopup::onTouchBegan(Touch* touch, Event* event) {

	return true;
}

void GameoverPopup::MakePopUp() {

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
	auto spriteScale = (winSize.width / sprite1->getContentSize().width) / 7;
	sprite1->setScale(spriteScale);
	sprite2->setScale(spriteScale);
	sprite1->setPosition(Point((pauseBg->getContentSize().height / 2), (pauseBg->getContentSize().height / 2) - 100));
	sprite2->setPosition(Point((pauseBg->getContentSize().height / 2), (pauseBg->getContentSize().height / 2)));
	pauseBg->addChild(sprite1);
	pauseBg->addChild(sprite2);

	this->addChild(pauseBg);

	// �ٽý��� ��ư
	auto restartMenu = MenuItemFont::create("�ٽý���", CC_CALLBACK_1(GameoverPopup::OnClickRestart, this));
	restartMenu->setColor(Color3B(255, 255, 255));
	restartMenu->setPosition(Point((pauseBg->getContentSize().height / 2), (pauseBg->getContentSize().height / 2)));
	restartMenu->setFontNameObj("fonts/DungGeunMo.ttf");


	// ����ȭ�� ��ư
	auto gomainMenu = MenuItemFont::create("����ȭ��", CC_CALLBACK_1(GameoverPopup::OnClickGoMain, this));
	gomainMenu->setColor(Color3B(255, 255, 255));
	gomainMenu->setPosition(Point((pauseBg->getContentSize().height / 2), (pauseBg->getContentSize().height / 2) - 100));
	gomainMenu->setFontNameObj("fonts/DungGeunMo.ttf");

	// �޴� ����
	auto menu = Menu::create(restartMenu, gomainMenu, NULL);
	menu->setPosition(Point::ZERO);

	pauseBg->addChild(menu, 1);

	// ȹ���� ����� ���
	auto scoreSprite = Sprite::create("images/Waterdrop.png");
	scoreSprite->setScale((winSize.width / scoreSprite->getContentSize().width) / 30);
	scoreSprite->setPosition(Point((pauseBg->getContentSize().height / 2) - 75, (pauseBg->getContentSize().height / 2) + 100));

	scoreText = ui::Text::create("", "fonts/DungGeunMo.ttf", 30);
	scoreText->setColor(Color3B(0, 0, 0));
	scoreText->setPosition(Point((pauseBg->getContentSize().height / 2) + 25, (pauseBg->getContentSize().height / 2) + 100));
	pauseBg->addChild(scoreText, 1);
	pauseBg->addChild(scoreSprite, 1);
}

void GameoverPopup::OnClickRestart(Ref* object) {
	((GameScene *)this->getParent())->Resume();
	((GameScene *)this->getParent())->Restart();
	this->removeFromParentAndCleanup(true);
}

void GameoverPopup::OnClickGoMain(Ref* object) {

}

void GameoverPopup::GetInfo(int score) {
	scoreText->setText(to_string(score) + "�� ȹ��");
}