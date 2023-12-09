import oasvalidator


def test_validate():
    validators = oasvalidator.init("thirdparty/cpp-oasvalidator/data/openAPI_example.json")
    error, error_msg = validators.validate_route("GET", "/v1/pets")
    assert error == oasvalidator.ValidationError.INVALID_ROUTE

