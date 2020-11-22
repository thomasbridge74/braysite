from django.test import TestCase
from .models import Player, SquadEntry
from shared.models import Squad


class PlayerTestCase(TestCase):
    def test_player_string(self):
        player = Player.objects.create(
            firstname="Bart",
            surname="Simpson",
            current=True,
            story="A boy from small town America",
        )
        self.assertEqual(str(player), "Bart Simpson")


class SquadEntryTestCase(TestCase):
    def setUp(self):
        self.squad = Squad.objects.create(
            name="Springfield Elementary softball team"
        )
        self.player = Player.objects.create(
            firstname="Bart",
            surname="Simpson",
            current=True,
            story="A boy from small town America",
        )
        self.squadentry = SquadEntry.objects.create(squad=self.squad, player=self.player)

    def test_basic_setup(self):
        self.assertEqual(self.squadentry.squad.name, "Springfield Elementary softball team")
        self.assertEqual(str(self.squadentry.player), "Bart Simpson")
