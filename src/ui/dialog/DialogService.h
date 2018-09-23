#pragma once
#include <optional>
#include <functional>
#include <Hypodermic/Container.h>
#include "ui/ViewBase.h"
#include "ui/IViewModel.h"
#include "ui/IView.h"
#include "Utilities.h"
#include "IDialog.h"

class DialogService
{
private:
	std::shared_ptr<ILogger> _logger;
	std::shared_ptr<Hypodermic::Container> _container;
	std::optional<std::shared_ptr<IView>> _currentDialogView;

public:
	std::optional<std::shared_ptr<IView>> CurrentDialogView() const { return _currentDialogView; }


	DialogService(const std::shared_ptr<ILogger>& logger, const std::shared_ptr<Hypodermic::Container>& container)
		: _logger(logger),
		  _container(container)
	{
	}

	template <class TViewModel, class = IsBaseOf<TViewModel, IViewModel>>
	void Show(std::function<void(std::shared_ptr<TViewModel>)> onShown,
	          std::function<void(std::shared_ptr<TViewModel>)> onClosed)
	{
		std::shared_ptr<IViewModel> viewModel = _container->resolve<TViewModel>();
		Reset(viewModel);

		std::shared_ptr<TViewModel> castedViewModel = std::static_pointer_cast<TViewModel>(viewModel);

		std::shared_ptr<IDialog> dialog = std::dynamic_pointer_cast<IDialog>(viewModel);
		dialog->OnClosed([=]()
		{
			onClosed(castedViewModel);
			_currentDialogView = {};
			_logger->Debug(viewModel->Name() + " closed");
		});

		onShown(castedViewModel);

		_currentDialogView = _container->resolve<ViewBase<TViewModel>>();

		_logger->Debug(viewModel->Name() + " shown");
	}

	template <class TViewModel, class = IsBaseOf<TViewModel, IViewModel>>
	void Reset(std::shared_ptr<TViewModel> viewModel)
	{
		std::shared_ptr<ICanReset> canReset = std::dynamic_pointer_cast<ICanReset>(viewModel);
		if (canReset)
		{
			canReset->Reset();
			_logger->Debug("Reset " + viewModel->Name());
		}
	}
};
