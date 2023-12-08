#include "oasvalidator_wrapper.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(oasvalidator, m)
{
    m.doc() = R"pbdoc(
         oasvalidator: : REST Request Validator
            -------------------------------------
            .. currentmodule:: oasvalidator
            .. autosummary::
               :toctree: _generate
               OASValidatorWrapper
               ValidationError
    )pbdoc";
    py::class_<OASValidatorWrapper>(m, "init")

        .def(py::init<const std::string&>(), py::arg("specs_path"), R"pbdoc(
            Initialize the OASValidatorWrapper with the path to the OAS specs.

            :param specs_path: The path to the OAS specs
            :return: An oasvalidator object)pbdoc")

        .def("validate_route", &OASValidatorWrapper::ValidateRoute, py::arg("method"), py::arg("http_path"), py::return_value_policy::reference, R"pbdoc(
            Validate the route of a request against the OAS specs.

            :param method: The HTTP method of the request.
            :param http_path: The HTTP path of the request.
            :return: A tuple of the validation error and error message)pbdoc")

        .def("validate_body", &OASValidatorWrapper::ValidateBody, py::arg("method"), py::arg("http_path"), py::arg("json_body"), py::return_value_policy::reference, R"pbdoc(
            Validate the body of a request against the OAS specs.

            :param method: The HTTP method of the request.
            :param http_path: The HTTP path of the request.
            :param json_body: The JSON body of the request.
            :return: A tuple of the validation error and error message)pbdoc")

        .def("validate_path_param", &OASValidatorWrapper::ValidatePathParam, py::arg("method"), py::arg("http_path"), py::return_value_policy::reference, R"pbdoc(
            Validate the path parameters of a request against the OAS specs.

            :param method: The HTTP method of the request.
            :param http_path: The HTTP path of the request.
            :return: A tuple of the validation error and error message)pbdoc")

        .def("validate_query_param", &OASValidatorWrapper::ValidateQueryParam, py::arg("method"), py::arg("http_path"), py::return_value_policy::reference, R"pbdoc(
            Validate the query parameters of a request against the OAS specs.

            :param method: The HTTP method of the request.
            :param http_path: The HTTP path of the request.
            :return: A tuple of the validation error and error message)pbdoc")

        .def("validate_headers", &OASValidatorWrapper::ValidateHeaders, py::arg("method"), py::arg("http_path"), py::arg("headers"), py::return_value_policy::reference, R"pbdoc(
            Validate the headers of a request against the OAS specs.

            :param method: The HTTP method of the request.
            :param http_path: The HTTP path of the request.
            :param headers: The headers of the request.
            :return: A tuple of the validation error and error message)pbdoc")

        .def("validate_request_basic", &OASValidatorWrapper::ValidateRequestBasic, py::arg("method"), py::arg("http_path"), py::return_value_policy::reference, R"pbdoc(
            Validate the basic request against the OAS specs.

            :param method: The HTTP method of the request.
            :param http_path: The HTTP path of the request.
            :return: A tuple of the validation error and error message)pbdoc")

        .def("validate_request_body", &OASValidatorWrapper::ValidateRequestBody, py::arg("method"), py::arg("http_path"), py::arg("json_body"), py::return_value_policy::reference,
             R"pbdoc(
            Validate the request body against the OAS specs.

            :param method: The HTTP method of the request.
            :param http_path: The HTTP path of the request.
            :param json_body: The JSON body of the request.
            :return: A tuple of the validation error and error message)pbdoc")

        .def("validate_request_headers", &OASValidatorWrapper::ValidateRequestHeaders, py::arg("method"), py::arg("http_path"), py::arg("headers"),
             py::return_value_policy::reference, R"pbdoc(
            Validate the request headers against the OAS specs.
            :param method: The HTTP method of the request.
            :param http_path: The HTTP path of the request.
            :param headers: The headers of the request.
            :return: A tuple of the validation error and error message)pbdoc")

        .def("validate_request_all", &OASValidatorWrapper::ValidateRequestAll, py::arg("method"), py::arg("http_path"), py::arg("json_body"), py::arg("headers"),
             py::return_value_policy::reference, R"pbdoc(
        Validate the request against the OAS specs.
        :param method: The HTTP method of the request.
        :param http_path: The HTTP path of the request.
        :param json_body: The JSON body of the request.
        :param headers: The headers of the request.
        :return: A tuple of the validation error and error message)pbdoc");

    py::enum_<ValidationError>(m, "ValidationError", py::arithmetic(), R"pbdoc(
    The validation error types.)pbdoc")

        .value("NONE", ValidationError::NONE, R"pbdoc(
    No validation error.)pbdoc")

        .value("INVALID_METHOD", ValidationError::INVALID_METHOD, R"pbdoc(
    The HTTP method is not defined in the OAS specs.)pbdoc")

        .value("INVALID_ROUTE", ValidationError::INVALID_ROUTE, R"pbdoc(
    The HTTP path is not defined in the OAS specs.)pbdoc")

        .value("INVALID_PATH_PARAM", ValidationError::INVALID_PATH_PARAM, R"pbdoc(
    The path parameters are not defined in the OAS specs.)pbdoc")

        .value("INVALID_QUERY_PARAM", ValidationError::INVALID_QUERY_PARAM, R"pbdoc(
    The query parameters are not defined in the OAS specs.)pbdoc")

        .value("INVALID_HEADER_PARAM", ValidationError::INVALID_HEADER_PARAM, R"pbdoc(
    The headers are not defined in the OAS specs.)pbdoc")

        .value("INVALID_BODY", ValidationError::INVALID_BODY, R"pbdoc(
    The body is not defined in the OAS specs.)pbdoc")

        .value("INVALID_RSP", ValidationError::INVALID_RSP, R"pbdoc(
    The response is not defined in the OAS specs.)pbdoc")
        .export_values();
}