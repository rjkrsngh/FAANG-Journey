#include "NotificationFactory.h"
#include "EmailNotification.h"
#include "SMSNotification.h"

std::unique_ptr<Notification> NotificationFactory::NotificationMaker(const std::string &type)
{
    Notification *notification{nullptr};
    if (type == "email")
        return std::make_unique<EmailNotification>();
    else if (type == "sms")
        return std::make_unique<SMSNotification>();

    return nullptr;
}