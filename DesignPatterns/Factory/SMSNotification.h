#include "Notification.h"

class SMSNotification : public Notification
{
public:
    SMSNotification() = default;
    void send(const std::string &msg) override;
};