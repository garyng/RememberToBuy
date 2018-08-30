﻿#pragma once
#include "ui/ViewModelBase.h"

class PendingViewModel : public ViewModelBase
{
public:
	PendingViewModel(const std::shared_ptr<NavigationService>& navigationService,
	                 const std::shared_ptr<ILogger>& logger);

	std::string Name() override;
};