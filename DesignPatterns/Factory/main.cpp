#include "Notification.h"
#include "NotificationFactory.h"

int main()
{
    std::unique_ptr<Notification> emailNotification = NotificationFactory::NotificationMaker("email");
    if (emailNotification != nullptr)
        emailNotification->send("This is an email notification");

    return 0;
}