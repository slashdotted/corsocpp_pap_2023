#include "alpha.h"

Alpha::Alpha(QObject *parent)
    : QObject{parent}
{

}

void Alpha::attivaAllarme()
{
    emit allarme("Al fuoco!");
}
