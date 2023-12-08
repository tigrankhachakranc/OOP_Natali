#include "ChangeSlideAction.hpp"

ChangeSlideAction::ChangeSlideAction(std::shared_ptr<Document> docPtr, std::shared_ptr<Slide> slidePtr, int currentIdx, int newIdx) :
    docPtr_(docPtr),
    slidePtr_(slidePtr),
    currentIdx_(currentIdx),
    newIdx_(newIdx)
{}

void ChangeSlideAction::doAction() {
    docPtr_->removeSlide(currentIdx_);
    docPtr_->insertSlide(slidePtr_, newIdx_);
}