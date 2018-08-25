#pragma once

class Colors
{
private:
	const ImVec4 _color;

	Colors(ImVec4 color) : _color(color)
	{
	}

public:
	static Colors DefaultWhite;
	static Colors Red500;
	static Colors Pink500;
	static Colors Purple500;
	static Colors DeepPurple500;
	static Colors Indigo500;
	static Colors Blue500;
	static Colors LightBlue500;
	static Colors Cyan500;
	static Colors Teal500;
	static Colors Green500;
	static Colors LightGreen500;
	static Colors Lime500;
	static Colors Yellow500;
	static Colors Amber500;
	static Colors Orange500;
	static Colors DeepOrange500;
	static Colors Brown500;
	static Colors Grey500;
	static Colors BlueGrey500;

	ImVec4 Color() const { return _color; }
	operator ImVec4() const { return _color; }
};
