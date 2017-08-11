#include "ConsoleView.h"



ConsoleView::ConsoleView()
{
	cout << "\n";
	cout << " *************************************" << endl;
	cout << " *                                   *" << endl;
	cout << " *      Welcome to BATTLESHIPS!      *" << endl;
	cout << " *                                   *" << endl;
	cout << " *************************************" << endl;
	cout << "\n\n";
	cout << " Press ENTER to start...";
}


ConsoleView::~ConsoleView()
{
}

void ConsoleView::initialize(Model* model)
{
	//const char ENRE = '\r';

	this->model = model;
	model->attach(this);

	Controller controller;
	controller.initialize(model, this);



}

void ConsoleView::activate()
{
}

void ConsoleView::display()
{
	model->getData();
	//display
}

void ConsoleView::update()
{
	display();
}
