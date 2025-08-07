#include "Notification.h"

class EmailNotification : public Notification
{
public:
    EmailNotification() = default;
    ~EmailNotification() = default;

    void send(const std::string &msg) override;
};