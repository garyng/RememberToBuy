#pragma once
class Fonts
{
private:
	int _index;

	Fonts(int index) : _index(index)
	{
	}

public:
	static Fonts RobotoRegular_Normal;
	static Fonts RobotoBold_Normal;

	static Fonts RobotoRegular_Title;

	static Fonts RobotoLight_Title1;
	static Fonts RobotoLight_Title2;

	static Fonts FontAwesome5_Title;


	int Index() const { return _index; }
	operator int() const { return _index; }
	operator ImFont*() const { return ImGui::GetIO().Fonts->Fonts[_index]; }
};
