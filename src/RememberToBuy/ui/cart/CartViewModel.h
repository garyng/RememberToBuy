#pragma once
#include "ui/ViewModelBase.h"

class CartViewModel : public ViewModelBase
{
public:
	CartViewModel(const std::shared_ptr<NavigationService>& navigationService, const std::shared_ptr<ILogger>& logger)
		: ViewModelBase(navigationService, logger)
	{
	}

	std::string Name() override
	{
		return NAMEOF(CartViewModel);
	}
};
