#include <oas_validator_imp.hpp>
#include <string>
#include <unordered_map>
#include <utility>

class OASValidatorWrapper
{
public:
    explicit OASValidatorWrapper(const std::string& specs_path);
    std::pair<ValidationError, std::string> ValidateRoute(const std::string& method, const std::string& http_path);
    std::pair<ValidationError, std::string> ValidateBody(const std::string& method, const std::string& http_path, const std::string& json_body);
    std::pair<ValidationError, std::string> ValidatePathParam(const std::string& method, const std::string& http_path);
    std::pair<ValidationError, std::string> ValidateQueryParam(const std::string& method, const std::string& http_path);
    std::pair<ValidationError, std::string> ValidateHeaders(const std::string& method, const std::string& http_path, const std::unordered_map<std::string, std::string>& headers);
    // Overloaded ValidateRequest Methods - need unique names for Python bindings
    std::pair<ValidationError, std::string> ValidateRequestBasic(const std::string& method, const std::string& http_path);
    std::pair<ValidationError, std::string> ValidateRequestBody(const std::string& method, const std::string& http_path, const std::string& json_body);
    std::pair<ValidationError, std::string> ValidateRequestHeaders(const std::string& method, const std::string& http_path,
                                                                   const std::unordered_map<std::string, std::string>& headers);
    std::pair<ValidationError, std::string> ValidateRequestAll(const std::string& method, const std::string& http_path, const std::string& json_body,
                                                               const std::unordered_map<std::string, std::string>& headers);

private:
    OASValidatorImp impl_;
};
