/**
 * @file Message.cpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#include "Message.hpp"

#include "Error.hpp"

#define CASE(m) if (messageName == #m) { message = std::make_shared<m>(); }

namespace messages {
    void Message::addProperty(const PropertySetter &setter, const PropertyGetter &getter, const std::string &name) {
        properties.emplace_back(setter, getter, name);
    }

    auto Message::toJson() const -> nlohmann::json {
        nlohmann::json json;
        for (const auto &[_, getter, name] : properties) {
            json["body"][name] = getter();
        }
        json["name"] = getMessageName();
        return json;
    }


    auto Message::fromJson(const nlohmann::json &j) -> std::shared_ptr<Message> {
        auto messageName = j.at("name").get<std::string>();
        std::shared_ptr<Message> message = nullptr;

        CASE(Error)

        if (message == nullptr) {
            throw std::runtime_error{"Invalid type or format!"};
        }

        for (const auto &[setter, _, name] : message->properties) {
            setter(j["body"][name]);
        }

        return message;
    }

}
