#include "stdafx.h"
#include "SourceStorage.h"

SourceStorage::SourceStorage(const std::shared_ptr<ILogger>& logger): JsonStorage<Source>(logger)
{
}

std::string SourceStorage::Filename() const
{
	return NAMEOF(Source)".json";
}

std::vector<Source> SourceStorage::DefaultData() const
{
	return std::vector<Source>
	{
		{0, "Daniel, Considine and Schinner", "2541 Maryam Parkway, Wiegandtown, Oman"},
		{1, "Windler - Christiansen", "7786 Ara Dale, Lake Kiara, Czech Republic"},
		{2, "Schimmel, Bode and Mills", "853 Colten Cliff, Hildamouth, Comoros"},
		{3, "Keeling - Kertzmann", "0679 Eveline Springs, North Conrad, Marshall Islands"},
		{4, "Frami, Gleason and Ziemann", "9378 Providenci Mission, Lonieborough, Cayman Islands"},
		{
			5, "Bergstrom, Watsica and Greenholt",
			"5895 Ivy Grove, Auerfurt, Antarctica (the territory South of 60 deg S)"
		},
		{6, "Goodwin - Cruickshank", "17159 Elliot Point, North Estefania, Saint Helena"},
		{7, "Ziemann - Glover", "59289 Volkman Neck, West Audreyfort, Germany"},
		{8, "DuBuque - McGlynn", "818 Olson Shores, East Shaylee, Niue"},
		{9, "Franecki, Bahringer and Jaskolski", "7208 Franecki Burgs, New Rudolphport, Central African Republic"}
	};
}
