

Projects="../../"

.PHONY: posts

posts:
	rsync -rupE $(Projects)/Common/Engineering/Software/Common/Languages/Cpp/ArrayTypeAndFunctionType Posts
	rsync -rupE $(Projects)/Common/Engineering/Software/Common/Languages/Cpp/Deducingtype Posts
	rsync -rupE $(Projects)/Common/Engineering/Software/Common/Languages/Cpp/TypesIdentifiersDeclarationsAndDefintitions Posts
	rsync -rupE $(Projects)/Common/Engineering/Software/Common/TheIngredientsOfProduct Posts
	rsync -rupE $(Projects)/Common/Common/OrganizationalStructure Posts
	rsync -rupE $(Projects)/Common/Engineering/Software/Common/Algorithms/IntroductionToAlgorithms/Ch31.NumberTheoreticAlgorithms Posts

