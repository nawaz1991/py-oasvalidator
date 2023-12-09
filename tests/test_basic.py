import os
import oasvalidator


def test_validate():
    # Get the directory of the current script
    dir_path = os.path.dirname(os.path.realpath(__file__))

    # Construct the path to the JSON file
    json_path = os.path.join(dir_path, "../thirdparty/cpp-oasvalidator/data/openAPI_example.json")

    # Use the constructed path in your test
    validators = oasvalidator.init(json_path)
    error, error_msg = validators.validate_route("GET", "/v1/pets")
    assert error == oasvalidator.ValidationError.INVALID_ROUTE
