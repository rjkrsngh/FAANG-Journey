package test

func GetClient() Client {
	testClient := Client{
		Name:        "abc",
		Age:         12,
		MemberSince: 2020,
	}

	return testClient
}
