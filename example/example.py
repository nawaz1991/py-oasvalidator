import oasvalidator

validators = oasvalidator.init("thirdparty/cpp-oasvalidator/data/openAPI_example.json")
error, error_msg = validators.validate_route("GET", "/v1/pets")

print(error)
print(error_msg)
