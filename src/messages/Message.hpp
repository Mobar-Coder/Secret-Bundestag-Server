/**
 * @file Message.hpp
 * @author paul
 * @date 01.12.20
 * Description here TODO
 */
#ifndef SECRETBUNDESTAGSERVER_MESSAGE_HPP
#define SECRETBUNDESTAGSERVER_MESSAGE_HPP

#include <string>
#include <vector>
#include <functional>
#include <memory>

#include <nlohmann/json.hpp>

#define CLASS(c) static const auto _registered_ = Message::addClass( \
    std::make_shared<c>, \
    [] (const Message *msg) { return dynamic_cast<const c*>(msg) != nullptr;}, \
    #c \
);

#define PROPERTY(p) addProperty( \
    [this] (const nlohmann::json &j) {this->p = j.get<decltype(this->p)>();}, \
    [this] () {return this->p;}, \
    #p,                          \
    _registered_\
); \

namespace messages {
    class Message {
            using json = nlohmann::json;

            using PropertySetter = std::function<void(const nlohmann::json &)>;
            using PropertyGetter = std::function<nlohmann::json()>;
            using PropertyInfo = std::tuple<PropertySetter, PropertyGetter, std::string>;

            using Factory = std::function<std::shared_ptr<Message>()>;
            using IsInstance = std::function<bool(const Message *)>;
            using ClassInfo = std::tuple<Factory, IsInstance, std::string>;
        public:
            Message() = default;

            Message(const Message &message) = delete;

            auto operator=(const Message &message) = delete;

            Message(Message &&message) = delete;

            auto operator=(Message &&message) = delete;

            auto operator==(const Message &message) const -> bool;

            [[nodiscard]] auto toJson() const -> nlohmann::json;

            static auto fromJson(const nlohmann::json &json) -> std::shared_ptr<Message>;

            virtual ~Message() = default;

            /*
             * Can throw an exception but if there is an exception we are fucked nonetheless
             */
            static auto addClass(const Factory &factory, const IsInstance &isInstance, const std::string &name) noexcept -> bool;

        protected:
            void addProperty(const PropertySetter &setter, const PropertyGetter &getter, const std::string &name,
                             bool registered);

        private:
            /**
             * @return a reference to a static local variable. Only used to handle initialization order.
             */
            static auto getClassesList() -> std::vector<ClassInfo>&;

            std::vector<PropertyInfo> properties;
    };
}

#endif //SECRETBUNDESTAGSERVER_MESSAGE_HPP
