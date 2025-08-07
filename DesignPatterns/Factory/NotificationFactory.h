#include <memory>
#include "Notification.h"

class NotificationFactory
{
public:
    NotificationFactory() = default;

    static std::unique_ptr<Notification> NotificationMaker(const std::string &type);
};