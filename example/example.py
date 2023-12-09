import oasvalidator
import os

dir_path = os.path.dirname(os.path.realpath(__file__))
json_path = os.path.join(dir_path, "../thirdparty/cpp-oasvalidator/data/openAPI_example.json")
validators = oasvalidator.init("thirdparty/cpp-oasvalidator/data/openAPI_example.json")
error, error_msg = validators.validate_route("GET", "/v1/pets")

print(error)
print(error_msg)
