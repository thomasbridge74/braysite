from django.test import TestCase
from shared.models import Columnist, Squad


class ColumnistTestCase(TestCase):

    def setUp(self):
        pass

    def test_columnist_name(self):
        columnist = Columnist.objects.create(name="Headmaster's Thoughts",
                                             author="Principal Skinner",
                                             description="Updates from Springfield Elementary")
        self.assertEqual(str(columnist), "Principal Skinner")


class SquadTestCase(TestCase):
    def test_squad(self):
        squad = Squad.objects.create(name="Brentwood Town")
        self.assertEqual(str(squad), "Brentwood Town")
