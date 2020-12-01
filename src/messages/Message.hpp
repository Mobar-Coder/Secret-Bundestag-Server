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

#define PROPERTY(p) addProperty( \
    [this] (const nlohmann::json &j) {this->p = j.get<decltype(this->p)>();}, \
    [this] () {return this->p;}, \
    #p \
);

namespace messages {
    class Message {
            using json = nlohmann::json;
            using PropertySetter = std::function<void(const nlohmann::json &)>;
            using PropertyGetter = std::function<nlohmann::json()>;
            using PropertyInfo = std::tuple<PropertySetter, PropertyGetter, std::string>;
        public:
            void addProperty(const PropertySetter &setter, const PropertyGetter &getter, const std::string &name);

            [[nodiscard]] virtual auto getMessageName() const -> std::string = 0;

            [[nodiscard]] auto toJson() const -> nlohmann::json;

            static auto fromJson(const nlohmann::json &json) -> std::shared_ptr<Message>;

        private:
            std::vector<PropertyInfo> properties;


    };
}

#endif //SECRETBUNDESTAGSERVER_MESSAGE_HPP
