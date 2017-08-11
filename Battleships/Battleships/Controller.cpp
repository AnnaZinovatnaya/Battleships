#include "Controller.h"



Controller::Controller()
{
}


Controller::~Controller()
{
}


void Controller::initialize(Model* model, ConsoleView* consoleView)
{
	this->model = model;
	this->consoleView = consoleView;

	model->attach(this);
}

void Controller::handleEvent()
{
	model->service();
}

void Controller::update()
{
	model->getData();
}
