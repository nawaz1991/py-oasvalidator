#include "oasvalidator_wrapper.hpp"

OASValidatorWrapper::OASValidatorWrapper(const std::string& specs_path)
    : impl_(specs_path)
{
}

std::pair<ValidationError, std::string> OASValidatorWrapper::ValidateRoute(const std::string& method, const std::string& http_path)
{
    std::string error_msg;
    ValidationError error = impl_.ValidateRoute(method, http_path, error_msg);
    return std::make_pair(error, error_msg);
}

std::pair<ValidationError, std::string> OASValidatorWrapper::ValidateBody(const std::string& method, const std::string& http_path, const std::string& json_body)
{
    std::string error_msg;
    ValidationError error = impl_.ValidateBody(method, http_path, json_body, error_msg);
    return std::make_pair(error, error_msg);
}

std::pair<ValidationError, std::string> OASValidatorWrapper::ValidatePathParam(const std::string& method, const std::string& http_path)
{
    std::string error_msg;
    ValidationError error = impl_.ValidatePathParam(method, http_path, error_msg);
    return std::make_pair(error, error_msg);
}

std::pair<ValidationError, std::string> OASValidatorWrapper::ValidateQueryParam(const std::string& method, const std::string& http_path)
{
    std::string error_msg;
    ValidationError error = impl_.ValidateQueryParam(method, http_path, error_msg);
    return std::make_pair(error, error_msg);
}

std::pair<ValidationError, std::string> OASValidatorWrapper::ValidateHeaders(const std::string& method, const std::string& http_path,
                                                                             const std::unordered_map<std::string, std::string>& headers)
{
    std::string error_msg;
    ValidationError error = impl_.ValidateHeaders(method, http_path, headers, error_msg);
    return std::make_pair(error, error_msg);
}

// Overloaded OASValidatorWrapper::ValidateRequest Methods - need unique names for Python bindings
std::pair<ValidationError, std::string> OASValidatorWrapper::ValidateRequestBasic(const std::string& method, const std::string& http_path)
{
    std::string error_msg;
    ValidationError error = impl_.ValidateRequest(method, http_path, error_msg);
    return std::make_pair(error, error_msg);
}

std::pair<ValidationError, std::string> OASValidatorWrapper::ValidateRequestBody(const std::string& method, const std::string& http_path, const std::string& json_body)
{
    std::string error_msg;
    ValidationError error = impl_.ValidateRequest(method, http_path, json_body, error_msg);
    return std::make_pair(error, error_msg);
}

std::pair<ValidationError, std::string> OASValidatorWrapper::ValidateRequestHeaders(const std::string& method, const std::string& http_path,
                                                                                    const std::unordered_map<std::string, std::string>& headers)
{
    std::string error_msg;
    ValidationError error = impl_.ValidateRequest(method, http_path, headers, error_msg);
    return std::make_pair(error, error_msg);
}

std::pair<ValidationError, std::string> OASValidatorWrapper::ValidateRequestAll(const std::string& method, const std::string& http_path, const std::string& json_body,
                                                                                const std::unordered_map<std::string, std::string>& headers)
{
    std::string error_msg;
    ValidationError error = impl_.ValidateRequest(method, http_path, json_body, headers, error_msg);
    return std::make_pair(error, error_msg);
}
